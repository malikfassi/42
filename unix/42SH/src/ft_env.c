/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:58:57 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:34:48 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>
#include <ftenv.h>

static int	ft_env_check_opts(char *str, char *opts)
{
	int			i;
	char		tmp[20];

	i = 1;
	ft_bzero(tmp, 20);
	while (str[i] != '\0')
	{
		if (ft_strichr(FTSH_BLT_OPTS, str[i]) >= 0)
		{
			if (ft_strichr(opts, str[i]) < 0)
				opts[ft_strlen(opts)] = str[i];
		}
		else
		{
			ft_strcpy(tmp, "illegal option -- ");
			tmp[18] = str[i];
			ft_error("env", tmp, NULL);
			ft_putstr_fd("usage: ", 2);
			ft_putstr_fd(FTSH_BLT_USAGE, 2);
			return (ft_error(FTSH_BLT_USAGE2, NULL, NULL));
		}
		i++;
	}
	return (0);
}

static int	ft_env_get_opts(char **cmd, char *opts)
{
	int			i;

	i = 1;
	while (cmd[i] != NULL)
	{
		if (ft_strichr(cmd[i], '-') != 0)
			return (i);
		if (ft_strcmp(cmd[i], "--") == 0)
			return (i + 1);
		if (ft_env_check_opts(cmd[i], opts) != 0)
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_env_opti_noarg(char ***envep)
{
	ft_env_print(*envep);
	ft_arrdel(envep);
	return (0);
}

int			ft_env(t_datas *datas, char **cmd)
{
	int			i;
	char		opts[FTSH_BLT_MAXOPTS + 1];
	t_bltenv	env;

	if (ft_strcmp(cmd[0], "env") != 0)
		return (-1);
	ft_bzero(opts, FTSH_BLT_MAXOPTS + 1);
	if (cmd[1] == NULL)
		return (ft_env_print(datas->env));
	i = ft_env_get_opts(cmd, opts);
	if (i == -1)
		return (1);
	else if (cmd[i] == NULL)
		return (0);
	env.opts = opts;
	i = ft_env_setep(datas, &env, cmd, i);
	if (i == -1)
		return (ft_error(FTSH_NAME, "env", "memory allocation failed."));
	else if (cmd[i] == NULL)
		return (ft_env_opti_noarg(&(env.ep)));
	if (ft_env_setav(&env, cmd, i) != 0)
		ft_env_exit(&env, 1);
	return (ft_env_exec(datas, &env));
}
