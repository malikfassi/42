/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/20 10:59:18 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/21 23:30:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_mult_char(char c, int times)
{
	if(times > 0)
	{
		ft_putchar(c);
		print_mult_char(c, times - 1);
	}
}

void	print_line(int stars, int spaces)
{
	print_mult_char(' ', spaces);
	ft_putchar('/');
	print_mult_char('*', stars);
	ft_putchar('\\');
	ft_putchar('\n');
}

void	gen_level(int current_line, int floor, int spaces, int stars, int size)
{
	if(current_line > 0)
	{
		if((current_line == (floor * floor + 5 * floor) / 2)
			&& current_line != size * (size + 5) / 2)
		{
			stars -= ((floor + 1) / 2) * 2 + 2;
			spaces += (1 + ((floor + 1) / 2));
			floor--;
		}

		gen_level(current_line - 1, floor, spaces + 1, stars - 2, size);
		print_line(stars, spaces);
	}
}

void	sastantua(int size)
{
	int		current_line;
	int		spaces;
	int		stars;
	int		i;
	
	i = 2;
	stars = 0;
	current_line = size * (size + 5) / 2;
	spaces = 0;
	while(i <= size)
	{
		stars += i / 2 + 1;
		i++;
	}
	stars *= 2;
	stars += 2 * current_line - 1;
	gen_level(current_line, size - 1, spaces, stars, size);
}
