/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:42:07 by gchateau          #+#    #+#             */
/*   Updated: 2013/11/30 14:53:38 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			chr;

	i = 0;
	chr = c;
	if (chr == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != chr)
	{
		if (s[i] == '\0')
			return (NULL);
		i += 1;
	}
	return ((char *)s + i);
}
