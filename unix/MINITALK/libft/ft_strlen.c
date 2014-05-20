/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 20:20:01 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:01:33 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

size_t		ft_strlen(const char *s)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}
