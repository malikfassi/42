/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 19:31:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/26 20:23:41 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <stdio.h>
void	print_prompt(void)
{
	ft_putstr("\x1B[37m(\x1B[0m");
	ft_putstr("\x1B[36m");
	ft_putstr(*find(get_env()->envp, "PWD=") + 4);
	ft_putstr("\x1B[0m");
	ft_putstr("\x1B[37m)\x1B[0m");
	ft_putstr("\x1B[31m$>\x1B[0m");
	ft_putstr("	\b");
}

char	****get_cmd(void)
{
	char	*line;
	char	**cmd_pvir;
	char 	****cmds;
	int		i;
    char    *tab[5] = {"|", "<", ">", "<<", ">>"};

	line = get_line();
	if (ft_strlen(line) == 0)
	{
		ft_strdel(&line);
		return (NULL);
	}
	cmd_pvir = ft_strsplit(line, ';');
	cmds = (char ****)malloc(sizeof(char ***) * (len_arr(cmd_pvir) + 1));
	i = 0;
	while (cmd_pvir[i])
	{
		cmds[i] = parse_op(cmd_pvir[i], tab);
		i++;
	}
	cmds[i] = NULL;
	free_arr(&cmd_pvir);
	ft_strdel(&line);
	return (cmds);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = get_env();
	env->fd_in = dup(0);
	env->fd_out = dup(1);
	set_envp(env, envp);
	while (argc == 1 && argv)
	{
		print_prompt();
		signal_gest();
		CMDS = get_cmd();
		if (!CMDS) //&& if cmd is empty
			continue ;
		exec_cmds();
		dup2(get_env()->fd_in, 0);
		dup2(get_env()->fd_out, 1);
	}
	return (0);
}
