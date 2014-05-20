/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:56:21 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/02 12:43:57 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp;

	if (n == 0)
		return (s1);
	tmp = (unsigned char*)malloc(n * sizeof(*tmp));
	if (tmp == NULL)
		return (s1);
	ft_memcpy(tmp, s2, n);
	ft_memcpy(s1, tmp, n);
	free(tmp);
	return (s1);
}
