/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:58:23 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/08 19:23:29 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	tmp[n];

	ft_memcpy(tmp, s2, n);
	ft_memcpy(s1, tmp, n);
	return (s1);
}
