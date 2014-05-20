/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/28 11:51:27 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/28 13:35:55 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int not_in_column(int **grid, int value, int column);
int not_in_line(int **grid, int value, int line);
int not_in_square(int **grid, int value, int line; int column);
int grid_is_valid(int **grid, int case_nb);

int	backtrack(int **grid, int case_nb, int line, int column)
{
	int	value;

	value = 1;
	while (value < 9)
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
