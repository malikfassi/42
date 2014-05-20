/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:33:07 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:35:57 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static int	ft_unsetenv_usage(char **cmd)
{
	int			len;

	len = ft_arrsize(cmd);
	if (len != 2)
	{
		if (len < 2)
			ft_error(FTSH_NAME, "unsetenv", "missing argument.");
		else if (len > 2)
			ft_error(FTSH_NAME, "unsetenv", "too many arguments.");
		ft_putendl_fd("usage: unsetenv [NAME]", 2);
		return (1);
	}
	return (0);
}

static int	ft_unsetenv_all(t_datas *datas)
{
	int			i;

	i = 0;
	while (datas->env[i] != NULL)
	{
		ft_strdel(&(datas->env[i]));
		i++;
	}
	return (0);
}

int			ft_unsetenv(t_datas *datas, char **cmd)
{
	int			res;

	if (ft_strcmp(cmd[0], "unsetenv") != 0)
		return (-1);
	if (ft_unsetenv_usage(cmd) != 0)
		return (1);
	if (ft_strcmp(cmd[1], "*") == 0)
		return (ft_unsetenv_all(datas));
	if (ft_getenv(datas->env, cmd[1]) == NULL)
		return (0);
	res = (ft_delvar(datas->env, cmd[1]) != 0 ? 1 : 0);
	return (res);
}
