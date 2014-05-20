/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 05:37:00 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 18:42:15 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

int				eval_expr(char **av, char *str)
{
	t_list	*expr;
	t_list	*rpn;
	char	*ret;

	str = (str) ? rmv_whtspc(str) : NULL;
	expr = (str) ? parse(av, str) : NULL;
	parse_parent(expr, av[2]);
	rpn = (expr) ? trans_rpn(expr, av) : NULL;
	ret = (rpn) ? calc_rpn(rpn, av) : NULL;
	if (!ret)
	{
		write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
		return (1);
	}
	ft_putstr(ret);
	return (0);
}

unsigned int	ft_uatoi(char *nbr)
{
	unsigned int	res;

	res = 0;
	while (*nbr)
	{
		res = *nbr - '0' + res * 10;
		nbr = nbr + 1;
	}
	return (res);
}

int				ft_fill_buff(char* buf, long long size)
{
	long long	size_read;
	long long	ret;

	size_read = 0;
	ret = read(0, buf, size);
	if (ret == -1)
	{
		write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
		return (1);
	}
	while (ret != 0)
	{
		size_read = size_read + ret;
		ret = read(0, buf, size - size_read);
		if (ret == -1)
		{
			write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
			return (1);
		}
	}
	buf[size_read] = 0;
	return (0);
}

int				ft_check_args_n_malloc_buf(int argc, char **argv, char **buf)
{
	long long	size;

	if (argc != 4)
	{
		write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
		return (1);
	}
	size = ft_uatoi(argv[3]);
	*buf = malloc(sizeof(**buf) * (size + 1));
	if (*buf == 0)
	{
		write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
		return (1);
	}
	return (ft_fill_buff(*buf, size));
}

int				main(int argc, char **argv)
{
	char	*buf;

	if (ft_check_args_n_malloc_buf(argc, argv, &buf))
	{
		return (1);
	}
	if (check_av(argv))
	{
		write(2, SYNTAXE_ERROR_MSG, ft_strlen(SYNTAXE_ERROR_MSG));
		return (1);
	}
	return (eval_expr(argv, buf));
}
