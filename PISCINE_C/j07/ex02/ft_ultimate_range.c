/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/25 04:41:36 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/25 23:16:53 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*ptr_range;
	int	i;
	
	i = 0;
	if (min < max)
	{
		len = max - min;
		ptr_range = malloc(sizeof(int *) * (len + 1));
		while (len > 0)
		{
			ptr_range[i] = min + i;
			len--;
			i++;
		}
		*range = ptr_range;
	}
	else
	{
		*range = NULL;
		return (0);
	}
	return (i);
}
