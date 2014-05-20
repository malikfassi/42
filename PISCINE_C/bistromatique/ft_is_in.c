/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/09 02:05:50 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 16:07:07 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

int		c_in_s(char c, char *str)
{
	long long	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		is_op(char c, char *av2)
{
	if (c == av2[0] || c == av2[2] || c == av2[3] || c == av2[4] || c == av2[5]
			|| c == av2[6])
	{
		return (1);
	}
	return (0);
}

int		is_pm(char c, char *av2)
{
	if (c == av2[0] || c == av2[1] || c == av2[4] || c == av2[5] || c == av2[6])
	{
		return (1);
	}
	return (0);
}

int		is_am(char c, char *av2)
{
	if (c == av2[2] || c == av2[3])
	{
		return (1);
	}
	return (0);
}

int		is_ammdm(char c, char *av2)
{
	if (c == av2[2] || c == av2[3] || c == av2[4] || c == av2[5] || c == av2[6])
	{
		return (1);
	}
	return (0);
}
