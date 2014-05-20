/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 03:06:57 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:18:06 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*str;

	index = 0;
	len = len + 1;
	str = (char*)malloc(len);
	if (str != 0)
	{
		while (index < len - 1)
		{
			str[index] = s[index + start];
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}

