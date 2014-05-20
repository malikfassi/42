/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 20:02:01 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:06:52 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;
	char	*ptr;

	new = (void *)malloc(sizeof(void) * (size));
	if (new == NULL)
		return (NULL);
	ptr = (char *)new;
	while (size--)
		*ptr++ = '\0';
	return (new);
}
