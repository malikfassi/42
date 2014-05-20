/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:17:02 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/22 00:23:43 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	if (size <= 0)
		return (NULL);
	ptr = (char *)malloc(size * sizeof(*ptr));
	ft_bzero(ptr, size);
	return ((void *)ptr);
}
