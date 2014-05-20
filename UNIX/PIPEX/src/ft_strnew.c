/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:37:19 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/31 14:18:47 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char*)ft_memalloc((size + 1) * sizeof(char));
	return (ptr);
}
