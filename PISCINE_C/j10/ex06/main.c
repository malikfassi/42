/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/29 23:38:11 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/30 22:32:22 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char **argv)
{
	int	(*op[11])(int, int);
	int	res;
	int	errcode;

	op[0] = &modulo;
	op[5] = &multiplication;
	op[6] = &addition;
	op[8] = &substraction;
	op[10] = &division;
	if (argc == 4)
	{
		errcode = errors(argv[2], argv[3]);
		if (! errcode)
		{
			res = op[*argv[2] - 37](to_int(argv[1]), to_int(argv[3]));
			ft_putnbr(res);
			ft_putchar('\n');
		}
		else if (errcode == 1)
		{
			write(1, "0\n", 2);
		}
	}
	return (0);
}
