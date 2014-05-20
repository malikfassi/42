/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 20:11:56 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:01:21 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ss1;
	char	*ss2;

	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while (n--)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
	}
	return (*ss1 - *ss2);
}
