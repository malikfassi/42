/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:40:25 by gchateau          #+#    #+#             */
/*   Updated: 2013/11/30 14:57:17 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t		tmp_siz;
	size_t		cat_len;
	char		*tmp_dst;
	const char	*tmp_src;

	tmp_siz = siz;
	tmp_dst = dst;
	tmp_src = src;
	while (tmp_siz-- && *tmp_dst != '\0')
		tmp_dst++;
	cat_len = tmp_dst - dst;
	siz -= cat_len;
	if (siz == 0)
		return (cat_len + (size_t)ft_strlen(src));
	while (*tmp_src != '\0')
	{
		if (siz != 1)
		{
			*tmp_dst++ = *tmp_src;
			siz--;
		}
		tmp_src++;
	}
	*tmp_dst = '\0';
	return (cat_len + (tmp_src - src));
}
