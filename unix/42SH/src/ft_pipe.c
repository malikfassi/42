/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:28:10 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/20 21:03:00 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <ftsh.h>

void	call_child(int *p, t_cmds *tree)
{
	int	ret;

	close(p[0]);
	dup2(p[1], 1);
	close(p[1]);
	if (ft_redir_right(tree) || ft_redir_left(tree))
		exit(-1);
	ret = implemented_function(get_env()->datas, tree->cmd);
	if (ret == 0)
		execution(tree);
	if (ret == 1)
		exit(0);
}

void	call_father(int *p, t_cmds *tree)
{
	close(p[1]);
	dup2(p[0], 0);
	close(p[0]);
	exec_tree(tree);
	exit(0);
}

int		grand_father(int *p, t_cmds *tree, int pid)
{
	wait(&pid);
	if (tree && tree->right && tree->right->cmd
			&& !ft_strcmp(tree->right->cmd[0], "exit"))
		ft_exit(get_env()->datas, ft_atoi(tree->right->cmd[1]));
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("42sh : fork failed\n", 2);
		return (-1);
	}
	if (pid == 0)
		call_father(p, tree->right);
	else
	{
		close(p[0]);
		close(p[1]);
		wait(&pid);
	}
	return (0);
}

int		ft_pipe(t_cmds *tree)
{
	pid_t	pid;
	int		p[2];

	if (pipe(p) == -1)
	{
		ft_putstr_fd("42sh : pipe failed\n", 2);
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("42sh : fork failed\n", 2);
		return (-1);
	}
	if (pid == 0)
		call_child(p, tree->left);
	else if (grand_father(p, tree, pid))
		return (-1);
	return (0);
}
