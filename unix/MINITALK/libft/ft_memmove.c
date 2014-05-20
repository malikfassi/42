/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 19:07:11 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:00:57 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*ss1;
	char	*ss2;

	ss1 = (char *)s1;
	ss2 = (char *)s2;
	ss2 = ss2 + n - 1;
	ss1 = ss1 + n - 1;
	while (n--)
		*ss1-- = *ss2--;
	return (s1);
}
