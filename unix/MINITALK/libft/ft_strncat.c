/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 16:16:17 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:02:44 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ss1;

	ss1 = s1;
	while (*ss1)
		ss1++;
	while (n--)
		*ss1++ = *s2++;
	*ss1 = '\0';
	return (s1);
}
