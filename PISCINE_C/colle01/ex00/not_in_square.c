/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_in_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/28 11:29:58 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/28 13:30:40 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	not_in_square(int **grid, int value, int line; int column)
{
	int	i;
	int	j;

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
