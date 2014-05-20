/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:07:54 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/27 19:08:24 by gchateau         ###   ########.fr       */
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
