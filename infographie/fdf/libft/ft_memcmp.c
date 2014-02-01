/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:45:53 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/08 19:22:43 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char*	tmp_s1;
	unsigned const char*	tmp_s2;

	tmp_s1 = s1;
	tmp_s2 = s2;
	while (n--)
	{
		if (*tmp_s1 != *tmp_s2)
		{
			return (*tmp_s1 - *tmp_s2);
		}
		tmp_s1++;
		tmp_s2++;
	}
	return (0);
}
