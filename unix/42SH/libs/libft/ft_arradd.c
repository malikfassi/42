/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:08:49 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/27 19:22:41 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_arradd(char ***arr, char *str)
{
	size_t	i;
	char	**tmp;
	char	**new;

	if ((!arr || *arr == NULL) && !str)
		return (-1);
	i = 0;
	tmp = *arr;
	new = (tmp == NULL ? ft_arrnew(1) : ft_arrnew((size_t)ft_arrsize(tmp) + 1));
	if (new == NULL)
		return (-1);
	if (tmp != NULL)
	{
		while (tmp[i] != NULL)
		{
			new[i] = tmp[i];
			tmp[i] = NULL;
			i++;
		}
		free((char **)tmp);
	}
	new[i] = str;
	*arr = new;
	return (0);
}
