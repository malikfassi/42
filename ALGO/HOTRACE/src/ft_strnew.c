/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:52:07 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:18:20 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools.h>

char	*ft_strnew(int size)
{
	char	*ptr;

	ptr = (char*)malloc(size + 1);
	if (ptr != NULL)
	{
		ft_bzero(ptr, size + 1);
	}
	return (ptr);
}

