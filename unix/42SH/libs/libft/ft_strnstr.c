/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:54:00 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/03 20:17:26 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while ((i + j) < n && j < (size_t)ft_strlen(s2)
					&& s1[i + j] == s2[j])
			{
				j += 1;
				if (s2[j] == '\0')
					return ((char *)s1 + i);
			}
		}
		i += 1;
	}
	return (NULL);
}
