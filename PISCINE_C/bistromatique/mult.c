/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/09 10:39:58 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 15:29:21 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

void    ft_memset(char *str, char c, long long len)
{
	long long	i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
}

void    mult_part(long long *val, char **str, char **av, int sign)
{
	char second_op;

	while (val[2] != 0)
	{
		val[5] = (sign) ? val[2] + val[0] : val[2] + val[0] - 1;
		val[4] = (str[0][val[5]]) ? str[0][val[5]] - av[1][0] : 0;
		second_op =  str[2][val[0] - 1] - av[1][0];
		val[3] = (str[1][val[2] - 1] - av[1][0]) * second_op + val[1] + val[4];
		str[0][val[5]] = val[3] % ft_strlen(av[1]) + av[1][0];
		val[1] = val[3] / 10;
		val[2]--;
	}
}

char *basic_mult(char *op1, char *op2, int sign, char **av)
{
	long long	val[7];
	char		*str[3];

	val[0] = ft_strlen(op2);
	val[2] = ft_strlen(op1);
	val[6] = (sign) ? val[0] + val[2] + 1 : val[0] + val[2]; 
	val[1] = 0;
	if ((str[0] = malloc(sizeof(char) * (val[6] + 1))))
	{
		ft_memset(str[0], 0, val[6] + 1);
		str[0][0] = (sign) ? av[2][3] : 0;
		str[1] = op1;
		str[2] = op2;
		while (val[0])
		{
			val[2] = ft_strlen(op1);
			val[1] = 0;
			mult_part(val, str, av, sign);
			val[5] = (sign) ? val[2] + val[0] : val[2] + val[0] - 1;
			str[0][val[5]] = val[1] + av[1][0];
			val[0]--;
		}
	}
	rmv_zero(str[0], sign, av[1]);
	return(str[0]);
}

char *mult(char *op1, char *op2, char **av)
{
	if (op1[0] == av[2][3] && op2[0] == av[2][3])
	{
		return (basic_mult(op2 + 1, op1 + 1, 0, av));
	}
	if (op1[0] != av[2][3] && op2[0] == av[2][3])
	{
		return (basic_mult(op1, op2 + 1, 1, av));
	}
	if (op1[0] == av[2][3] && op2[0] != av[2][3])
	{
		return (basic_mult(op1 + 1, op2, 1, av));
	}
	return (basic_mult(op1, op2, 0, av));
}
