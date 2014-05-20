/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbusi <florian.busi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/28 17:44:44 by fbusi             #+#    #+#             */
/*   Updated: 2013/07/28 23:19:46 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		not_in_column(int grid[9][9], int value, int column);
int		not_in_line(int grid[9][9], int value, int line);
int		not_in_square(int grid[9][9], int value, int line, int column);
int		grid_is_valid(int grid[9][9], int case_nb);
int		backtrack(int grid[9][9], int case_nb, int line, int column);
int		is_valid(char c);
void	display_grid(int grid[9][9]);

int		backtrack(int grid[9][9], int case_nb, int line, int column)
{
	int		value;

	value = 1;
	while (value <= 9)
	{
		if (not_in_line(grid, value, line)
				&& not_in_column(grid, value, column)
				&& not_in_square(grid, value, line, column))
		{
			grid[line][column] = value;
			if (grid_is_valid(grid, case_nb + 1))
			{
				return (1);
			}
		}
		value++;
	}
	grid[line][column] = 0;
	return (0);
}

void	display_grid(int grid[9][9])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
}

void	get_grid(int argc, char **argv, int grid[9][9])
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = 8;
		while (j >= 0)
		{
			grid[i][j] = (argv[i][j] != '.') ? argv[i][j] - 48 : 0;
			j--;
		}
		i++;
	}
}

int		is_valid(char c)
{
	return (('1' <= c && c <= '9') || c == '.' || c == '0');
}

int		check_input(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	j = 9;
	i = 0;
	while (j == 9 && i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!is_valid(argv[i][j]))
			{
				return (0);
			}
			if (argv[i][j] != '.')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return ((i == 9) && j == 9 && count >= 17);
}
