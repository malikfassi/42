/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:50:57 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:50:58 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_explode_len(const char *s, const char *str, size_t slen)
{
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0' && ft_strncmp(s + i, str, slen) != 0)
		i++;
	return (i);
}

char			**ft_explode(const char *s, const char *str)
{
	size_t			slen;
	size_t			len;
	char			**arr;

	if (!s || !str)
		return (NULL);
	if ((arr = ft_arrnew(0)) == NULL)
		return (NULL);
	slen = (size_t)ft_strlen(str);
	while (*s != '\0')
	{
		if (ft_strncmp(s, str, slen) != 0)
		{
			len = ft_explode_len(s, str, slen);
			if (ft_arradd(&arr, ft_strsub(s, 0, len)) < 0)
			{
				ft_arrdel(&arr);
				return (NULL);
			}
			s += len;
		}
		else
			s += slen;
	}
	return (arr);
}
