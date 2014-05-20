/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:05:58 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/17 17:30:55 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_arrnew(size_t size)
{
	char	**arr;

	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (size)
		arr[size--] = NULL;
	return (arr);
}
