/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 18:46:17 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:00:27 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*ss1;
	char	*ss2;

	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while (n--)
		*ss1++ = *ss2++;
	return (s1);
}
