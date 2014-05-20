/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:48:44 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/02 12:42:23 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*cpy;

	if (!s)
		return (NULL);
	i = 0;
	cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(*cpy));
	if (cpy != NULL)
	{
		while (s[i] != '\0')
		{
			cpy[i] = s[i];
			i += 1;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}
