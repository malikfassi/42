/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/25 01:18:22 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/25 23:08:36 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i] != '\0')
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strdup(char	*src)
{
	char	*str;

	str = malloc(sizeof(*str) * get_length(src));
	if (str != NULL)
	{
		ft_strcpy(str, src);
	}
	return (str);
}
