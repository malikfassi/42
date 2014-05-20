/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:12:46 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/18 17:42:18 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s)
{
	size_t	i;
	size_t	j;
	int		space;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	space = 1;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) == 0)
		{
			if (j > 0 && space == 1)
				s[j++] = ' ';
			space = 0;
			s[j] = s[i];
			j++;
		}
		else
			space = 1;
		i++;
	}
	ft_bzero((s + j), i - j);
	return (s);
}
