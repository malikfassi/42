/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:54:36 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:30:36 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*	ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char*	tmp_s;

	tmp_s = s;
	while (n-- != 0)
	{
		if (*tmp_s == (unsigned char) c)
		{
			return ((void *) tmp_s);
		}
		else
		{
			++tmp_s;
		}
	}
	return (NULL);
}
