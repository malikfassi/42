/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/27 23:32:10 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/28 15:54:36 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cette fonction recupere les arguments et les mets dans un tableau
// arguments :
// 			argc nb de paramatres (sans le nom du fichier)
// 			argv liste des paramtres (sans le nom du fichier);

#include <stdio.h>

void	get_grid(int argc, char **argv, int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			grid[i][j] = '0' + (int)argv[i][j];
			printf("%d",grid[i][j]);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int *grid[9][9];

	get_grid(argc - 1, argv + 1, *grid);
	return (0);
}
