/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arridel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:04:03 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/04/19 09:04:05 by mfassi-f         ###   ########.fr       */
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
