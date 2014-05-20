/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 18:37:27 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/01 02:19:17 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*bb;

	bb = (char *)b;
	while (len--)
		*bb++ = c;
	return (b);
}
