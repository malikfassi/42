/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:05:11 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/04/19 09:05:14 by mfassi-f         ###   ########.fr       */
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
