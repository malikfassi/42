/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:03:52 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/04/19 09:03:56 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	size_t	len;
	size_t	i;
	char	**new;

	if (!arr)
		return (NULL);
	len = (size_t)ft_arrsize(arr);
	new = ft_arrnew(len);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	return (new);
}
