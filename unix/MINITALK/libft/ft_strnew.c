/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 20:07:49 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:07:16 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*ptr;

	str = (char *)malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	ptr = str;
	while (size--)
		*ptr++ = '\0';
	return (str);
}
