/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:28:34 by gchateau          #+#    #+#             */
/*   Updated: 2013/11/30 14:49:44 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char			*tmp1;
	const unsigned char		*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	while (n--)
	{
		*tmp1++ = *tmp2++;
		if (*(tmp2 - 1) == (unsigned char)c)
			return (tmp1);
	}
	return (NULL);
}
