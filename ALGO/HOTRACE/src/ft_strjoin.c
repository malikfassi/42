/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 02:55:32 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:19:31 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	index;
	char	*str1;
	char	*str2;

	str = (char*)malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	index = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	if (str != NULL)
	{
		while (str1[index] != '\0')
		{
			str[index] = str1[index];
			index++;
		}
		while (*str2 != '\0')
		{
			str[index] = *str2;
			str2++;
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}

