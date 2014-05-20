/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/09 21:33:31 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 21:36:37 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

char	*sub_part1(long long *s, int *v, char *r, char **av)
{
	s[2] = (v[3]) ? max(s[0], s[1]) + 1 : max(s[0], s[1]);
	r = (char *)malloc(sizeof(char) * (s[2] + 1));
	r[0] = (v[3]) ? av[2][3] : av[1][0];
	r[s[2] + 1] = '\0';
	v[2] = 0;
	s[3] = (v[3]) ? 0 : -1;
	v[4] = ft_strlen(av[1]);
	return (r);
}

void	sub_part2(long long *s, int *v, char *r, char **av)
{
	v[2] = v[0] - v[1] - v[2];
	r[s[2]] = (v[2] < 0) ? av[1][v[2] + v[4]] : av[1][v[2]];
	v[2] = (v[2] < 0) ? 1 : 0;
	s[0]--;
	s[1]--;
	s[2]--;
}

char	*subtraction(char *op1, char *op2, char **av)
{
	long long	s[4];
	int			v[5];
	char		*r;

	s[0] = ft_strlen(op1) - 1;
	s[1] = ft_strlen(op2) - 1;
	v[3] = 0;
	if (s[0] < s[1] || (s[0] == s[1] && b_strcmp(op1, op2, av[1]) < 0))
	{
		ft_swap(&op1, &op2);
		v[3] = 1;
	}
	r = sub_part1(s, v, r, av);
	while (s[2] > s[3])
	{
		v[0] = (s[0] > -1) ? b_val(op1[s[0]], av[1]) : 0;
		v[1] = (s[1] > -1) ? b_val(op2[s[1]], av[1]) : 0;
		sub_part2(s, v, r, av);
	}
	rmv_zero(r, v[3], av[1]);
	return (r);
}

char	*sub(char *op1, char *op2, char **av)
{
	if (op1[0] == av[2][3] && op2[0] == av[2][3])
	{
		return (subtraction(op2 + 1, op1 + 1, av));
	}
	if (op1[0] != av[2][3] && op2[0] == av[2][3])
	{
		return (addition(op1, op2 + 1, 0, av));
	}
	if (op1[0] == av[2][3] && op2[0] != av[2][3])
	{
		return (addition(op1 + 1, op2, 1, av));
	}
	return (subtraction(op1, op2, av));
}
