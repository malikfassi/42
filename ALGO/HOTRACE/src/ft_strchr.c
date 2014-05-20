/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 02:58:14 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:19:26 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools.h>

char	*ft_strchr(const char *str, int c)
{
	int	length;
	int	index;
	char	*found;
	char	character;

	length = ft_strlen((char*)str) + 1;
	index = 0;
	character = c;
	found = 0;
	while ((index < length) && found == 0)
	{
		if (str[index] == c)
		{
			found = &((char*)str)[index];
		}
		index++;
	}
	return (found);
}

