/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 09:52:50 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:48:04 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_ptr;
	size_t	i;

	i = 0;
	new_ptr = NULL;
	if (s && f && (new_ptr = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		while (i < ft_strlen(s))
		{
			new_ptr[i] = f(s[i]);
			i++;
		}
		new_ptr[i] = '\0';
	}
	return (new_ptr);
}
