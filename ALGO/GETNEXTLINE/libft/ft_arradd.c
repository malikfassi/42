/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:03:21 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/04/19 09:13:19 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
