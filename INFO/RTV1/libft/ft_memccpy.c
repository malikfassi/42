/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:49:44 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:28:27 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*tmp_s1;
	unsigned const char	*tmp_s2;

	tmp_s1 = s1;
	tmp_s2 = s2;
	while (n-- != 0)
	{
		if (*tmp_s2 != (unsigned char) c)
		{
			*tmp_s1++ = *tmp_s2++;
		}
		else
		{
			*tmp_s1++ = *tmp_s2++;
			return (tmp_s1);
		}
	}
	return (NULL);
}
