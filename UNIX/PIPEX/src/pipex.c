/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 14:34:16 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/31 18:50:27 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <pipex.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

static int		open_file(char *file_name, char **envp, int flags, int mode)
{
	int		i;
	char	*pwd;
	char	*new_path;
	char	*part_path;

	i = findi(envp, "PWD=");
	pwd = envp[i] + 4;
	part_path = ft_strjoin(pwd, "/");
	new_path = ft_strjoin(part_path, file_name);
	ft_strdel(&part_path);
	if ((flags == (O_RDWR | O_CREAT)) || ft_access(new_path))
	{
		if (mode)
			i = open(new_path, flags, mode);
		else
			i = open(new_path, flags);
		ft_strdel(&new_path);
		return (i);
	}
	ft_strdel(&new_path);
	return (-1);
}

static void		call_child(int *p, char **argv, char **envp)
{
	int		in;
	char	**cmd;

	close(p[0]);
	dup2(p[1], 1);
	close(p[1]);
	in = open_file(argv[1], envp, O_RDONLY, 0);
	if (in == -1)
		exit(0);
	dup2(in, 0);
	cmd = ft_strsplit(argv[2], ' ');
	if (execve(get_path(envp, cmd), cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		exit(0);
	}
}

static void		call_father(int *p, char **argv, char **envp)
{
	int		out;
	char	**cmd;
	char	*path;

	out = open_file(argv[4], envp, O_RDWR | O_CREAT | O_TRUNC, 777);
	wait(0);
	close(p[1]);
	dup2(p[0], 0);
	close(p[0]);
	dup2(out, 1);
	cmd = ft_strsplit(argv[3], ' ');
	path = get_path(envp, cmd);
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_arr(&cmd);
		ft_strdel(&path);
		exit(0);
	}
}

int				main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		p[2];

	if (argc != 5)
	{
		ft_putstr_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (0);
	}
	if (pipe(p) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Fork failed\n", 2);
		return (0);
	}
	if (pid == 0)
		call_child(p, argv, envp);
	else
		call_father(p, argv, envp);
	return (0);
}
