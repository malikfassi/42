/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 20:29:03 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:46:42 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = ft_strlen(dst);
	res = ft_strlen(src) + ft_strlen(dst);
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (src[i] && (size > j + 1))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (res);
}
