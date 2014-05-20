/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:07:52 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/29 19:10:12 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <intlist.h>
#include <intlist2.h>
#include <stdio.h>
#include <parse.h>

int	main(int argc, char **argv)
{
	t_intlist	*l_a;
	t_intlist	*l_b;

	if (argc == 1)
		return (-1);
	l_b = NULL;
	if (!param_ok(argv + 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	l_a = fill_l_a(argc, argv);
	while (!is_sorted(l_a))
	{
		sort_la(&l_a, &l_b);
		sort_lb(&l_b, &l_a);
	}
	return (0);
}
