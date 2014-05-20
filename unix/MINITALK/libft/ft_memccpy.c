/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 18:58:00 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:00:38 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*ss1;
	char	*ss2;

	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while (n--)
	{
		if (*ss2 == c)
		{
			*ss1++ = c;
			return (ss1);
		}
		*ss1++ = *ss2++;
	}
	return (NULL);
}
