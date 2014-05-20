/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 23:50:18 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:09:47 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const char	*ss1;
	const char	*ss2;
	char		*new;
	char		*ptr;

	ss1 = s1;
	ss2 = s2;
	while (*ss1)
		ss1++;
	while (*ss2)
		ss2++;
	new = (char *)malloc(sizeof(char) * ((ss1 - s1) + (ss2 - s2) + 1));
	if (new == NULL)
		return (NULL);
	ptr = new;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	ss1 = NULL;
	ss2 = NULL;
	ptr = NULL;
	return (new);
}
