/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/01 10:00:19 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/01 19:49:48 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_tail.h"
#include <stdio.h>
int	errors1(char **argv, int argc)
{
	int	errcode;
	
	errcode = 0;
	if (argv[1][1] == 'c')
	{
		errcode = errors2(argv, argc);
	}
	else
	{
		errcode = 0;
		ft_putstr("tail: illegal option -- ");
		ft_putstr(&argv[1][1]);
		ft_putstr("\n");
	}
	return (errcode);
}

int	errors2(char **argv, int argc)
{
	int	errcode;
	int	is_num;

	errcode = 1;
	is_num = (argc >= 3) ? is_numeric(argv[2], 0) : 0;
	if ((!is_numeric(argv[1], 2) || !is_num))
	{
		if (!is_numeric(argv[1], 2)) 
		{
			ft_putstr("tail: illegal offset -- ");
			ft_putstr(argv[1] + 2);
		}
		else if (*(argv[1] + 2) == '\0' && argc == 2)
		{
			ft_putstr("tail: option requires an argument -- c");
			ft_putstr("\nusage: tail [-c #] [file ...]");
		}
		else
		{
			ft_putstr(argv[2]);
		}
		errcode = 0;
		ft_putstr("\n");
	}
	return (errcode);
}
