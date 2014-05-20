/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmesas <mesaskevin@live.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/03 18:50:04 by kmesas            #+#    #+#             */
/*   Updated: 2013/08/04 17:13:47 by kmesas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_line(int size, char c_begin, char c_middle, char c_end)
{
	ft_putchar(c_begin);
	while ((size - 1) > 1)
	{
		ft_putchar(c_middle);
		size--;
	}
	if (size > 1)
	{
		ft_putchar(c_end);
	}
	ft_putchar('\n');
}

void	colle(int x, int y)
{
	if (x > 0 && y > 0)
	{
		ft_print_line(x, '/', '*', '\\');
		y--;
		while (y > 1)
		{
			ft_print_line(x, '*', ' ', '*');
			y--;
		}
		if (y > 0)
		{
			ft_print_line(x, '\\', '*', '/');
		}
	}
}

