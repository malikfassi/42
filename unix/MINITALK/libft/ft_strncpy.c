/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 21:38:21 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:02:23 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*ss1;

	ss1 = s1;
	while (n--)
	{
		if (*s2 == '\0')
			*ss1++ = '\0';
		else
			*ss1++ = *s2++;
	}
	return (s1);
}
