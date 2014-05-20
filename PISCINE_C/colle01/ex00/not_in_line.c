/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_in_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/28 11:26:18 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/28 13:29:57 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	not_in_line(int **grid, int value, int line)
{
	int	column;

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
