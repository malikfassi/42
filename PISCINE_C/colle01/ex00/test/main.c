/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbusi <florian.busi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/28 23:06:12 by fbusi             #+#    #+#             */
/*   Updated: 2013/07/28 23:23:39 by fbusi            ###   ########.fr       */
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
void	get_grid(int argc, char **argv, int grid[9][9]);
int		check_input(int argc, char **argv);

int		main(int argc, char **argv)
{
	int		grid[9][9];

	argc--;
	argv++;
	if (!check_input(argc, argv))
	{
		write(1, "Error\n", 6);
	}
	else
	{
		get_grid(argc, argv, grid);
		if (grid_is_valid(grid, 0))
		{
			display_grid(grid);
		}
		else
		{
			write(1, "Error\n", 6);
		}
	}
	return (0);
}
