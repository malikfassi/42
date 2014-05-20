/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/25 02:39:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/25 23:16:15 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*range;
	int	i;
	
	i = 0;
	if (min < max)
	{
		len = max - min;
		range = malloc(sizeof(int *) * (len + 1));
		while (len > 0)
		{
			range[i] = min + i;
			len--;
			i++;
		}
	}
	else
	{
		return(range);
	}
	return (range);
}
