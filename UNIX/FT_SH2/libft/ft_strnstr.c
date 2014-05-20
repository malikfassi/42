/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:49:58 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:50:21 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	count_s2;
	size_t	count_s1;

	count_s2 = 0;
	count_s1 = 0;
	while (*(s1 + count_s1) && n)
	{
		if (count_s2 == ft_strlen(s2))
			return ((char *)(s1));
		if (*(s1 + count_s1) != *(s2 + count_s2))
			return (ft_strnstr(s1 + count_s1 + 1, s2, --n));
		count_s2++;
		count_s1++;
		n--;
	}
	if (count_s2 == ft_strlen(s2))
		return ((char *)(s1));
	return (NULL);
}
