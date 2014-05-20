/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:49:55 by gchateau          #+#    #+#             */
/*   Updated: 2013/11/30 14:59:02 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (size_t)ft_strlen(dest);
	while (i < n && src[i] != '\0')
	{
		dest[len + i] = src[i];
		i += 1;
	}
	dest[len + i] = '\0';
	return (dest);
}
