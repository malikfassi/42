/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/30 14:35:18 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/30 22:33:32 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "do_op.h"

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0'
			&& ((str[i] <= '9' && str[i] >= '0') || (str[0] == '-' && i == 0)))
	{
		i++;
	}
	return (i);
}

int	ten_power(int a)
{
	int	result = 1;
	int	count;

	count = 0;
	while (count < a)
	{
		result *= 10;
		count++;
	}
	return (result);
}

int	to_int(char *str)
{
	int	result;
	int	count;
	int	i;

	count = get_length(str);
	result = 0;
	i = (str[0] == '-') ? 1 : 0;
	while (i < count)
	{
		result += (str[i] - 48) * ten_power(count - i - 1);
		i++;
	}
	if (str[0] == '-')
	{
		result *= -1 ;
	}
	return (result);
}
