/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 19:31:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/18 13:40:22 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <signal.h>
#include <stdio.h>

/*
** GLOBAL VARIABLES
*/

char **g_envp;

/*
**
*/
void	print_prompt(char **envp)
{
	ft_putstr("\x1B[37m(\x1B[0m");
	ft_putstr("\x1B[36m");
	ft_putstr(*find(envp, "PWD=") + 4);
	ft_putstr("\x1B[0m");
	ft_putstr("\x1B[37m)\x1B[0m");
	ft_putstr("\x1B[31m$>\x1B[0m");
//	ft_putstr("$>");
}

char	*get_path(char **envp, char **cmd)
{
	char	**paths;
	char	*part_path;
	char	*path;

	paths = ft_strsplit(envp[0] + 5, ':');
	part_path = ft_strjoin(search_path(paths, cmd[0]), "/");
	path = ft_strjoin(part_path, cmd[0]);
	ft_strdel(&part_path);
	free_arr(&paths);
	return (path);
}

char	***get_cmd(void)
{
	char	*line;
	char	**cmd;
	char 	***cmds;
	int		i;

	i = 0;
	line = get_line();
	if (ft_strlen(line) == 0)
	{
		ft_strdel(&line);
		return (NULL);
	}

	cmd = ft_strsplit(line, ';');
	while (cmd[i])
		i++;
	cmds = (char ***)malloc(sizeof(char **) * (i + 1));
	i = 0;
	while (cmd[i])
	{
		cmds[i] = ft_strsplit(cmd[i], ' ');
		i++;
	}
	cmds[i] = NULL;
	free_arr(&cmd);
	ft_strdel(&line);
	return (cmds);
}

int	implemented_function(char **cmd, char ***envp)
{
	if (!cmd)
		return (1);
	if (ft_strcmp(cmd[0], "exit") == 0)
	{
		free_arr(&cmd);
		return (-1);
	}
	else if (ft_strcmp(cmd[0], "env") == 0)
		ft_env(*envp, cmd);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		ft_cd(cmd, *envp);
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		*envp = ft_setenv(cmd, *envp);
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		*envp = ft_unsetenv(cmd, *envp);
	else
		return (0);
	return (1);
}


void	signal_ctrl_c(int sig)
{
	(void) sig;
	ft_putstr("\b \b\b \b\n");
	print_prompt(g_envp);
}

void	signal_ctrl_z(int sig)
{
	(void) sig;
	ft_putstr("\b \b\b \b");
}

void	signal_gest(void)
{
	signal(SIGINT, signal_ctrl_c);
	signal(SIGTSTP, signal_ctrl_z);
}

int	main(int argc, char **argv, char **envp)
{
	char	***cmds;
	pid_t	pid;
	int		ret;
	char	**cmd;
	
	g_envp = envp;
	while (argc == 1 && argv)
	{
		print_prompt(envp);
		signal_gest();
		cmds = get_cmd();
		if (!cmds)
			continue ;
		while (cmds && *cmds)
		{
			cmd = *cmds;
			cmds++;
			ret = implemented_function(cmd, &envp);
			if (ret == -1)
				exit(0);
			else if (ret == 1 && !*cmds)
				break ;
			pid = fork();
			if (pid == 0 && execve(get_path(envp, cmd), cmd, envp) == -1)
			{
				ft_putstr("42sh: command not found: ");
				ft_putendl(cmd[0]);
				exit(0);
			}
			if (pid < 0)
				ft_putstr("fork failed\n");
			wait(0);
		}
	}
	return (0);
}
