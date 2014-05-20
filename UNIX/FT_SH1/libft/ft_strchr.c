/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:46:07 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/08 19:26:05 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/libft.h"

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
