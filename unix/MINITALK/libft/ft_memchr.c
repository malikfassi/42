/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 20:07:01 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:01:08 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ss;

	ss = (char *)s;
	while (n--)
	{
		if (*ss == c)
			return (ss);
		ss++;
	}
	return (NULL);
}
