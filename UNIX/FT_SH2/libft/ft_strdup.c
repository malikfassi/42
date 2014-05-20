/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:20:31 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:44:52 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char*s1)
{
	char	*cpy;

	cpy = (char*)malloc(sizeof(*cpy) * ft_strlen(s1));
	if (cpy != NULL)
	{
		ft_strcpy(cpy, s1);
	}
	return (cpy);
}
