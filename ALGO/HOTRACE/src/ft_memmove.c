/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:27:06 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:17:38 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools.h>

void	*ft_memmove(void *s1, const void *s2, int n)
{
	char	*str1;
	char	*str2;
	int	index;

	str1 = (char*)s1;
	str2 = (char*)s2;
	index = 0;
	if (str1 >= str2 && str1 <= (str2 + ft_strlen(str2)))
	{
		while (index < n)
		{
			str1[n - index - 1] = str2[n - index - 1];
			index++;
		}
	}
	else
	{
		while (index < n)
		{
			str1[index] = str2[index];
			index++;
		}
	}
	return (s1);
}

