/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:22:08 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:22:09 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arriteri(char **arr, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (arr && (*f))
	{
		i = 0;
		while (arr[i] != NULL)
		{
			(*f)(i, arr[i]);
			i++;
		}
	}
}
