/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:46:07 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:42:57 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (*(s + count) != '\0' || (char)c == '\0')
	{
		if (*(s + count) == (char) c)
		{
			return ((char *)&s[count]);
		}
		count++;
	}
	return (NULL);
}
