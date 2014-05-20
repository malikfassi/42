/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:58:57 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:47:34 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <ftsh.h>
#include <ftenv.h>

int		ft_env_exec(t_datas *datas, t_bltenv *env)
{
	pid_t	pid;

	env->exe = ft_findexe(datas->path, env->av[0]);
	if (env->exe == NULL)
		return (1);
	if ((pid = fork()) < 0)
	{
		ft_error(FTSH_NAME, "env", "new processus failed.");
		return (ft_env_exit(env, 1));
	}
	else if (pid == 0)
	{
		if (execve(env->exe, env->av, env->ep) < 0)
			exit(ft_error(FTSH_NAME, "env", "execution failed."));
	}
	else
	{
		waitpid(pid, &(datas->status), 0);
		ft_response(datas);
		return (ft_env_exit(env, 0));
	}
	return (0);
}
