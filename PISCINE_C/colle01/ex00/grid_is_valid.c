/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/28 11:36:23 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/28 13:34:31 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	backtrack(int **grid, int case_nb, int line, int column);

int	grid_is_valid(int **grid, int case_nb)
{
	int	line;
	int	column;

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
