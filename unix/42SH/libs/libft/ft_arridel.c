/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arridel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:21:14 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:49:53 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_arridel(char ***arr, size_t index)
{
	size_t	siz;
	size_t	i;
	char	**new;

	if (*arr == NULL || (siz = (size_t)ft_arrsize(*arr)) == 0)
		return (-1);
	if (index >= siz)
		return (1);
	i = 0;
	new = ft_arrnew(siz - 1);
	while ((*arr)[i] != NULL)
	{
		if (i != index)
			new[i] = (*arr)[i];
		else
			free((char *)arr[i]);
		i++;
	}
	ft_arrdel(arr);
	*arr = new;
	return (0);
}
