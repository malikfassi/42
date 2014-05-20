/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 20:58:53 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:40:45 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <outc.h>
#include <libft.h>
#include <stdlib.h>

int	len_arr(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != -1)
		i++;
	return (i);
}

int	*update_array(int *array, int to_delete)
{
	int	*new_array;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new_array = (int *)malloc((len_arr(array) * sizeof(int)));
	ft_bzero(new_array, len_arr(array) * sizeof(int));
	new_array[len_arr(array) - 1] = -1;
	while ((array)[i] != -1)
	{
		if (to_delete != i)
		{
			new_array[j] = array[i];
			j++;
		}
		i++;
	}
	return (new_array);
}
