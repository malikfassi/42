/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 23:48:19 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/26 23:50:22 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_arrfree(char ***arr, size_t size)
{
	size_t	i;
	char	**tmp;

	if (*arr == NULL)
		return ;
	i = 0;
	tmp = *arr;
	while (i < size)
	{
		if (tmp[i] != NULL)
			free((char *)tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free((char **)tmp);
	*arr = NULL;
}
