/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:36:05 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/08 19:29:16 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/libft.h"

size_t	ft_strlen(const char *s1)
{
	size_t	count;

	count = 0;
	while (*(s1 + count) != '\0')
	{
		count++;
	}
	return (count);
}
