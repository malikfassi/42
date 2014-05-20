/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 16:35:54 by scadoux           #+#    #+#             */
/*   Updated: 2014/01/31 16:36:18 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;
	unsigned int	dst_size;
	unsigned int	src_size;

	ptr = dst;
	while (*ptr)
		ptr++;
	i = (ptr - dst);
	j = 0;
	dst_size = (ptr - dst);
	ptr = (char *)src;
	while (*ptr)
		ptr++;
	src_size = (ptr - src);
	while ((dst_size + j + 1) < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (dst_size < size)
		return (dst_size + src_size);
	return (size + src_size);
}
