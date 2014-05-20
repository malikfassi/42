/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:08:23 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/08 19:23:40 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = s;
	while (n-- != 0)
		{
			*tmp = (unsigned char)c;
			tmp++;
		}
	return (s);
}
