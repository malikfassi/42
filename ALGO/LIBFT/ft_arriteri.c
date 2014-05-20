/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:04:14 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/04/19 09:04:16 by mfassi-f         ###   ########.fr       */
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
