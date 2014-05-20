/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/09 12:11:26 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 18:12:55 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

int	b_val(char c, char *av1)
{
	int	i;

	i = 0;
	while (av1[i])
	{
		if (av1[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	check_rep(char **av)
{
	char		*tmp;

	tmp = av[1];
	while (*tmp)
	{
		if (c_in_s(*tmp, tmp + 1))
		{
			return (1);
		}
		tmp++;
	}
	tmp = av[2];
	while (*tmp)
	{
		if (c_in_s(*tmp, tmp + 1))
		{
			return (1);
		}
		tmp++;
	}
	return (0);
}

int	check_av(char **av)
{
	long long	len[2];
	long long	i;

	len[0] = ft_strlen(av[1]);
	len[1] = ft_strlen(av[2]);
	if (len[0] > 225 || len[1] != 7)
	{
		return (1);
	}
	i = 0;
	while (i < 7)
	{
		if (c_in_s(av[2][i], av[1]))
		{
			return (1);
		}
		i++;
	}
	return (check_rep(av));
}
