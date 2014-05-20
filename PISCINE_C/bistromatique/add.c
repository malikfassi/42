/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/06 21:11:31 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 21:34:29 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

char	*addition(char *op1, char *op2, int sign, char **av)
{
	long long	s[4];
	int			v[4];
	char		*r;
	
	s[0] = ft_strlen(op1) - 1;
	s[1] = ft_strlen(op2) - 1;
	s[2] = (sign) ? max(s[0], s[1]) + 2 : max(s[0], s[1]) + 1;
	r = (char *)malloc(sizeof(char) * (s[2] + 1));
	r[0] = (sign) ? av[2][3] : 0;
	r[s[2] + 1] = '\0';
	v[2] = 0;
	s[3] = (sign) ? 0 : -1;
	v[3] = ft_strlen(av[1]);
	while (s[2] > s[3])
	{
		v[0] = (s[0] > -1) ? b_val(op1[s[0]], av[1]) : 0;
		v[1] = (s[1] > -1) ? b_val(op2[s[1]], av[1]) : 0;
		v[2] += v[0] + v[1];
		r[s[2]] = (v[2] >= v[3]) ? av[1][v[2] - v[3]] : av[1][v[2]];
		v[2] = (v[2] >= v[3]) ? 1 : 0;	
		s[0]--;
		s[1]--;
		s[2]--;
	}
	rmv_zero(r, sign, av[1]);
	return (r);
}

char	*add(char *op1, char *op2, char **av)
{
	if (op1[0] == av[2][3] && op2[0] == av[2][3])
	{
		return (addition(op1 + 1, op2 + 1, 1, av));
	}
	if (op1[0] != av[2][3] && op2[0] == av[2][3])
	{
		return (subtraction(op1, op2 + 1, av));
	}
	if (op1[0] == av[2][3] && op2[0] != av[2][3])
	{
		return (subtraction(op2, op1 + 1, av));
	}
	return (addition(op1, op2, 0, av));
}
