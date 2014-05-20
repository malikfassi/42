/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 23:36:15 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:52:14 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

char	*ft_getvar(t_datas *datas, char *key)
{
	char	*tmp;

	if (!key)
		return (NULL);
	tmp = ft_getenv(datas->env, key);
	if (tmp != NULL)
		return (tmp);
	return (ft_getenv(datas->local, key));
}
