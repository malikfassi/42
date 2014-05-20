/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_in_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/28 11:26:32 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/28 13:29:22 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	not_in_column(int **grid, int value, int column)
{
	int	line;

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
