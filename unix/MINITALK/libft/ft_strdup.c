/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 20:23:24 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:01:50 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char			*ss1;
	char			*s2;
	char			*ss2;

	ss1 = (char *)s1;
	while (*ss1)
		ss1++;
	s2 = (char *)malloc(sizeof(char) * (ss1 - s1 + 1));
	if (s2 == NULL)
		return (NULL);
	ss2 = (char *)s2;
	while (*s1)
		*ss2++ = *s1++;
	*ss2 = '\0';
	return (s2);
}
