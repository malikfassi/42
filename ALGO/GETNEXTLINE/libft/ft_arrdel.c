/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:04:32 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/04/19 09:04:34 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_arrdel(char ***arr)
{
	size_t	i;
	char	**tmp;

	if (!arr || !*arr)
		return ;
	i = 0;
	tmp = *arr;
	while (tmp[i] != NULL)
	{
		free((char *)tmp[i]);
		i++;
	}
	free((char **)tmp);
	*arr = NULL;
}
