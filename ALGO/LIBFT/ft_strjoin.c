/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:59:13 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/02/08 22:24:31 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	if (s1 && s2\
	&& (ptr = (char *)\
		malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		ft_strcpy(ptr, s1);
		i = (ft_strlen(s1) == 0) ? 0 : ft_strlen(s1) - 1;
		ft_strcat(&ptr[i], s2);
	}
	return (ptr);
}
