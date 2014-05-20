/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbusi <florian.busi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/28 23:00:47 by fbusi             #+#    #+#             */
/*   Updated: 2013/07/28 23:13:01 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		not_in_column(int grid[9][9], int value, int column);
int		not_in_line(int grid[9][9], int value, int line);
int		not_in_square(int grid[9][9], int value, int line, int column);
int		grid_is_valid(int grid[9][9], int case_nb);
int		backtrack(int grid[9][9], int case_nb, int line, int column);
int		is_valid(char c);
void	display_grid(int grid[9][9]);

int		not_in_line(int grid[9][9], int value, int line)
{
	int		column;

	column = 0;
	while (column < 9)
	{
		if (grid[line][column] == value)
		{
			return (0);
		}
		column++;
	}
	return (1);
}

int		not_in_column(int grid[9][9], int value, int column)
{
	int		line;

	line = 0;
	while (line < 9)
	{
		if (grid[line][column] == value)
		{
			return (0);
		}
		line++;
	}
	return (1);
}

int		not_in_square(int grid[9][9], int value, int line, int column)
{
	int		first_i;
	int		first_j;
	int		i;
	int		j;

	first_i = 3 * (line / 3);
	first_j = 3 * (column / 3);
	i = first_i;
	while (i < first_i + 3)
	{
		j = first_j;
		while (j < first_j + 3)
		{
			if (grid[i][j] == value)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		grid_is_valid(int grid[9][9], int case_nb)
{
	int		line;
	int		column;

	line = case_nb / 9;
	column = case_nb % 9;
	if (case_nb == 81)
	{
		return (1);
	}
	if (grid[line][column] != 0)
	{
		return (grid_is_valid(grid, case_nb + 1));
	}
	return (backtrack(grid, case_nb, line, column));
}
