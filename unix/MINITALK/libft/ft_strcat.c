/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 16:06:48 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:02:35 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ss1;

	ss1 = s1;
	while (*ss1)
		ss1++;
	while (*s2)
		*ss1++ = *s2++;
	*ss1 = '\0';
	return (s1);
}
