/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:45:59 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/22 00:38:51 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[(size_t)start + i] != '\0')
	{
		str[i] = s[(size_t)start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
