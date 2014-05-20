/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmesas <mesaskevin@live.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/03 18:48:19 by kmesas            #+#    #+#             */
/*   Updated: 2013/08/03 18:49:07 by kmesas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

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
		ft_print_line(x, 'A', 'B', 'A');
		y--;
		while (y > 1)
		{
			ft_print_line(x, 'B', ' ', 'B');
			y--;
		}
		if (y > 0)
		{
			ft_print_line(x, 'C', 'B', 'C');
		}
	}
}

