/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:53:00 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:26:52 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	ptr = NULL;
	if (size <= 0)
		return (NULL);
	if ((ptr = (char *)malloc(size)))
	{
		ft_bzero(ptr, size);
	}
	return ((void *)ptr);
}
