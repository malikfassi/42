/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 18:13:56 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:04:21 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*ss1;
	const char	*ss2;

	ss1 = s1;
	ss2 = s2;
	while (*s1 && n--)
	{
		s2 = ss2;
		ss1 = s1;
		while (*ss1 == *s2 && *s2)
		{
			ss1++;
			s2++;
		}
		if (*s2 == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
