/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:04:45 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/04/19 09:04:47 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_arrfree(char ***arr, size_t size)
{
	size_t	i;
	char	**tmp;

	if (*arr == NULL)
		return ;
	i = 0;
	tmp = *arr;
	while (i < size)
	{
		if (tmp[i] != NULL)
			free((char *)tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free((char **)tmp);
	*arr = NULL;
}
