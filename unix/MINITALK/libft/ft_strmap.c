/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 20:40:26 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:16:55 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*ss;
	unsigned int	size;
	char			*new;

	ss = (char *)s;
	size = 0;
	while (*ss++)
		size++;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	ss = new;
	while (*s)
		*ss++ = f(*s++);
	return (new);
}
