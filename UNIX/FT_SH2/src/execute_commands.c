/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:22:21 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/26 22:11:49 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <stdio.h> //dfghjkl
char    *get_path(char **cmd)
{
    char    **paths;
    char    *part_path;
    char    *path;

    paths = ft_strsplit(*find(ENVP, "PATH=") + 5, ':');
    part_path = ft_strjoin(search_path(paths, cmd[0]), "/");
    path = ft_strjoin(part_path, cmd[0]);
    ft_strdel(&part_path);
    free_arr(&paths);
    return (path);
}

int implemented_function(char **cmd)
{
	if (!cmd)
		return (1);
	if (ft_strcmp(cmd[0], "exit") == 0)
	{
		free_arr(&cmd);
		return (-1);
	}
	else if (ft_strcmp(cmd[0], "env") == 0)
		ft_env(cmd);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		ft_cd(cmd);
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		ENVP = ft_setenv(cmd);
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		ENVP = ft_unsetenv(cmd);
	else
		return (0);
	return (1);
}

void	non_impl_funct(char **cmd)
{
	char	*path;
	pid_t	pid;

	pid = fork();
	path = get_path(cmd);
	if (pid == 0 && execve(path, cmd, ENVP) == -1)
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		ft_strdel(&path);
		exit(0);
	}
	if (pid < 0)
	{
		ft_strdel(&path);
		ft_putstr_fd("42sh: fork failed\n", 2);
	}
	wait(0);
	ft_strdel(&path);
}

int	exec_func(char **cmd)
{
	int		ret;

	ret = implemented_function(cmd);
	if (ret == -1)
		exit(0);
	if (ret == 1 && !*CMDS)
		return (-1);
	else if (ret == 1)
		cmd++;
	non_impl_funct(cmd);
	return (0);
}

int	choose_redir_case(char ****cmd)
{
	if (!ft_strcmp(*(*cmd + len_arr_triple(*cmd) - 2)[0], ">"))
	{
		if (ft_redir_right(*cmd, len_arr_triple(*cmd)))
			return (-1);
	}
	if ((*cmd && !ft_strcmp(*(*cmd)[0], "<")) ||
			(*(*cmd + 1) && !ft_strcmp(*(*cmd + 1)[0], "<")))
	{
		if (ft_redir_left(&*cmd))
			return (-1);
	}
	return (0);
}

int	choose_case(char ****cmd)
{
	if (ft_strcmp(*(*cmd + 1)[0], "|") == 0)
	{
		if (ft_pipe(*cmd))
			return (-1);
		cmd += 2;
		return (0);
	}
	if (!ft_strcmp(*(*cmd + len_arr_triple(*cmd) - 2)[0], ">")
			|| (*cmd && !ft_strcmp(*(*cmd)[0], "<")) ||
			(*(*cmd + 1) && !ft_strcmp(*(*cmd + 1)[0], "<")))
	{
		if (choose_redir_case(cmd))
			return (-1);
	}
	else
	{
		ft_putstr_fd("42sh: parse error\n", 2);
		return (-1);
	}
	return (1);
}


int	exec_all_funcs(char ***cmd)
{
	int		len_cmd;
	int		ret;

	while (cmd && *cmd)
	{
		len_cmd = len_arr_triple(cmd);
		if (len_cmd >= 2)
		{
			ret = choose_case(&cmd);
			if (ret == -1)
				return (-1);
			else if (ret == 0)
				break ;
		}
		else
		{
			if (exec_func(*cmd))
				return (-1) ;
			cmd++;
		}
	}
	return (0);
}

void	exec_cmds()
{
	char	***cmd;

	while (CMDS && *CMDS)
	{
		cmd = *CMDS;
		CMDS++;
		if (exec_all_funcs(cmd))
		{
			dup2(get_env()->fd_in, 0);
			dup2(get_env()->fd_out, 1);
			continue ;
		}
		if (cmd && !*cmd)
		{
			dup2(get_env()->fd_in, 0);
			dup2(get_env()->fd_out, 1);
			break ;
		}
	}
}
