/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:10:58 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:27:20 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*tmp_s1;
	unsigned const char	*tmp_s2;

	tmp_s1 = s1;
	tmp_s2 = s2;
	while (n-- != 0)
	{
		*tmp_s1++ = *tmp_s2++;
	}
	return (s1);
}
