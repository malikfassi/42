/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_print.c                                     :+:      :+:    :+:   */
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

int		ft_env_print(char **env)
{
	int		i;

	i = 0;
	if (env == NULL)
		return (0);
	while (env[i] != NULL)
	{
		ft_putendl(env[i]);
		i++;
	}
	return (0);
}
