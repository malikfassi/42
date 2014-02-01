/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:28:09 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/26 20:41:40 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <stdio.h>
void	exec_pipe(char **cmd)
{
	int	ret;

	ret = implemented_function(cmd);
	if (ret == 1)
		exit(0);
	if (execve(get_path(cmd), cmd, ENVP) == -1)
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		exit(0);
	}
}

void	call_child(int *p, char **cmd)
{
	close(p[0]);
	dup2(p[1], 1);
	close(p[1]);
	exec_pipe(cmd);
}

void	call_father(int *p, char ***cmd)
{
	close(p[1]);
	dup2(p[0], 0);
	close(p[0]);
	exec_all_funcs(cmd);
	exit(0);
}

int		grand_father(int *p, char ***cmd, int pid)
{
	wait(&pid);
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Fork failed\n", 2);
		return (-1);
	}
	if (pid == 0)
		call_father(p, cmd + 2);
	else
	{
		close(p[0]);
		close(p[1]);
		wait(&pid);
	}
	return (0);
}

int	ft_pipe(char ***cmd)
{
	pid_t	pid;
	int		p[2];

	if (pipe(p) == -1)
	{
		ft_putstr_fd("pipe failed\n", 2);
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Fork failed\n", 2);
		return (-1);
	}
	if (pid == 0)
		call_child(p, cmd[0]);
	else
		if (grand_father(p, cmd, pid))
			return (-1);
	return (0);
}
