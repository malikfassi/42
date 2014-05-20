/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/20 15:07:05 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/21 22:43:50 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_putchar(char c);

void	first_line(int count_line, int count_char, int width)
{
	if (count_line == 1)
	{
		if (count_char == 1)
			ft_putchar('/');
		else if (count_char == width)
			ft_putchar('\\');
		else
			ft_putchar('*');
	}
}

void	select_char(int count_line, int count_char, int width, int length)
{
	first_line(count_line, count_char, width);
	if (count_line == length)
	{
		if (count_char == 1) 
			ft_putchar('\\');
		else if (count_char == width)
			ft_putchar('/');
		else
			ft_putchar('*');
	}
	else
	{
		if ((count_char == 1) || (count_char == width))
			ft_putchar('*');
		else
			ft_putchar(' ');
	}
}

void	colle(int width, int length)
{
	int		count_line;
	int		count_char;

	count_line = 1;
	count_char = 1;
	if( (width > 0) && (length > 0))
	{
		while (count_line <= length )
		{
			while (count_char <= width)
			{
				select_char(count_line, count_char, width, length);
				count_char++;
			}
			ft_putchar('\n');
			count_char = 1;
			count_line++;
		}
	}
}
