/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/21 22:19:30 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/21 22:40:59 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

void	first_line(int count_line, int count_char, int width)
{
	if (count_line == 1)
	{
		if ((count_char == 1))
			ft_putchar('A');
		else if(count_char == width)
			ft_putchar("C");
		else
			ft_putchar('B');
	}

}

void	select_char(int count_line, int count_char, int width, int length)
{
	first_line(count_line, count_char, width);
	if (count_line == length)
	{
		if ((count_char == 1))
			ft_putchar('C');
		else if(count_char == width)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else
	{
		if ((count_char == 1) || (count_char == width))
			ft_putchar('B');
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
