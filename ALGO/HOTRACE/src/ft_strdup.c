/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 02:57:05 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:18:13 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools.h>

char	*ft_strdup(const char *str)
{
	int	length;
	int	index;
	char	*new_str;

	length = ft_strlen((char*)str);
	index = 0;
	new_str = (char*)malloc(length + 1);
	new_str[length] = '\0';
	while (index < length)
	{
		new_str[index] = str[index];
		index++;
	}
	return (new_str);
}

