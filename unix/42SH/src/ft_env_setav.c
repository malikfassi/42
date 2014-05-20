/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_setav.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:58:57 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:47:34 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>
#include <ftenv.h>

int		ft_env_setav(t_bltenv *env, char **cmd, int i)
{
	int		j;
	int		n;

	n = 0;
	j = i;
	while (cmd[j++] != NULL)
		n++;
	env->av = ft_arrnew(n);
	if (env->av == NULL)
		return (ft_error(FTSH_NAME, "env", "memory allocation failed."));
	j = 0;
	while (cmd[i] != NULL)
	{
		env->av[j] = ft_strdup(cmd[i]);
		if (env->av[j] == NULL)
		{
			ft_arrdel(&(env->av));
			return (ft_error(FTSH_NAME, "env", "memory allocation failed"));
		}
		j++;
		i++;
	}
	return (0);
}
