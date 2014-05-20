/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implemented_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 22:42:00 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 19:35:46 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static int	ft_find_blt(t_datas *datas, t_fblt **fblt, char **cmd, char **tmp)
{
	int				i;
	int				res;

	i = 0;
	while (fblt[i] != NULL)
	{
		res = (fblt[i])(datas, cmd);
		if (res != -1)
		{
			if (*tmp != cmd[1])
				ft_strdel(tmp);
			*tmp = ft_itoa(res);
			ft_setvar(&(datas->local), "?", *tmp);
			ft_strdel(tmp);
			return (1);
		}
		i++;
	}
	if (*tmp != cmd[0])
		ft_strdel(tmp);
	return (0);
}

int			implemented_function(t_datas *datas, char **cmd)
{
	char			*tmp;
	static t_fblt	*fblt[11] =

	{
	&ft_cd, &ft_echo, &ft_history, &ft_env, &ft_setenv, &ft_unsetenv,
	&ft_set, &ft_unset, &ft_color, &ft_export, NULL
	};
	tmp = ft_strtolower(ft_strdup(cmd[0]));
	if (tmp == NULL)
		tmp = ft_strtolower(cmd[0]);
	if (ft_strcmp(tmp, "exit") == 0)
	{
		if (tmp != cmd[0])
			ft_strdel(&tmp);
		ft_exit(datas, ft_atoi(cmd[1]));
	}
	return (ft_find_blt(datas, fblt, cmd, &tmp));
}
