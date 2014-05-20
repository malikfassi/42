/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:24:22 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/20 21:01:21 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "ftsh.h"

void	execution(t_cmds *tree)
{
	tree->cmd_path = ft_findexe(get_env()->datas->path, tree->cmd[0]);
	if (!tree->cmd_path)
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(tree->cmd[0], 2);
		exit(1);
	}
	if (execve(tree->cmd_path, tree->cmd, get_env()->datas->env) == -1)
	{
		ft_putstr_fd("42sh: command failed: ", 2);
		ft_putendl_fd(tree->cmd[0], 2);
		exit(1);
	}
}

int		exec_cmd(t_cmds *tree)
{
	pid_t	pid;
	int		ret;

	parse_var(tree);
	if (ft_redir_right(tree) || ft_redir_left(tree))
		return (-1);
	if (!tree->cmd || (tree->cmd && !tree->cmd[0]))
		return (0);
	ret = implemented_function(get_env()->datas, tree->cmd);
	if (ret == 0)
	{
		pid = fork();
		if (pid == 0)
			execution(tree);
		if (pid < 0)
		{
			ft_putstr_fd("Fork failed\n", 2);
			return (-1);
		}
		waitpid(pid, &(get_env()->datas->status), 0);
		ft_response(get_env()->datas);
	}
	return (0);
}

int		exec_tree(t_cmds *tree)
{
	int		success;

	if (!tree)
		return (0);
	if (tree->type == CMD)
	{
		if (exec_cmd(tree))
			return (-1);
		files_rredir(tree);
		files_drredir(tree);
		unlink(TMP_FILE_R);
		unlink(TMP_FILE_L);
		success = ft_atoi(ft_getenv(get_env()->datas->local, "?"));
		if (tree->right && ((tree->right->flag == OR && success != 0)
			|| (tree->right->flag == AND && success == 0)
			|| (tree->right->flag == UNDEF)))
			exec_tree(tree->right);
	}
	else if (tree->type == PIPE)
		ft_pipe(tree);
	return (0);
}

void	exec_trees(void)
{
	int		i;

	i = 0;
	while (get_env()->cmds && get_env()->cmds[i])
	{
		if (!exec_tree(get_env()->cmds[i]))
		{
			i++;
			dup2(get_env()->fd_in, 0);
			dup2(get_env()->fd_out, 1);
		}
		else
		{
			free_all_trees(get_env()->cmds);
			return ;
		}
	}
	free_all_trees(get_env()->cmds);
}
