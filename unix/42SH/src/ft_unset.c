/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:33:07 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:37:23 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static int	ft_unset_usage(char **cmd)
{
	int			len;

	len = ft_arrsize(cmd);
	if (len != 2)
	{
		if (len < 2)
			ft_error(FTSH_NAME, "unset", "missing argument.");
		else if (len > 2)
			ft_error(FTSH_NAME, "unset", "too many arguments.");
		ft_putendl_fd("usage: unset [NAME]", 2);
		return (1);
	}
	return (0);
}

static int	ft_unset_all(t_datas *datas)
{
	int			i;

	i = 6;
	while (datas->local[i] != NULL)
	{
		ft_strdel(&(datas->local[i]));
		i++;
	}
	return (0);
}

int			ft_unset(t_datas *datas, char **cmd)
{
	int			i;
	int			res;
	int			len;

	if (ft_strcmp(cmd[0], "unset") != 0)
		return (-1);
	i = 0;
	if (ft_unset_usage(cmd) != 0)
		return (1);
	len = ft_strlen(cmd[1]);
	if (len == 0)
		return (ft_error(FTSH_NAME, "unset", "invalid key."));
	if (ft_strcmp(cmd[1], "*") == 0)
		return (ft_unset_all(datas));
	if (ft_getenv(datas->local, cmd[1]) == NULL)
		return (0);
	while (datas->local[i] != NULL)
	{
		if (ft_strncmp(datas->local[i], cmd[1], len) == 0
			&& datas->local[i][len] == '=' && i < 6)
			return (ft_error("unset", cmd[1], "locked system variable."));
		i++;
	}
	res = (ft_delvar(datas->local, cmd[1]) != 0 ? 1 : 0);
	return (res);
}
