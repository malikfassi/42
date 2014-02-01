/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:23:35 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/02 20:39:48 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <vector.h>
#include <mlxOp.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <libft.h>
#include <get_next_line.h>
#include <parse.h>


void	fdf(int fd, void *mlx, void * win)
{
	int		ret;
	char	**splitted_line1;
	char	**splitted_line2;
	char	*line;
	double 	j;

	line = NULL;
	splitted_line1 = NULL;
	ret = get_next_line(fd, &line);
	splitted_line2 = ft_strsplit(line, ' ');
	j = 0;
	while(ret)
	{
		splitted_line1 = splitted_line2;
		if ((ret = get_next_line(fd, &line)))
		{
			splitted_line2 = ft_strsplit(line, ' ');
			j++;
		}
		display(splitted_line1, splitted_line2, mlx, win, j);
		printf("2\n");
		//free_array((void ***)&splitted_line1);
		printf("3\n");
	}
	printf("4\n");
	//if (splitted_line2)
	//	free_array((void ***)&splitted_line2);
	printf("5\n");
}

void	display(char** splitted_line1, char **splitted_line2, void *mlx, void *win, double j)
{
	int 		i;
	t_3Dvector	*vector3D_start;
	t_3Dvector	*vector3D_end;
	double		z;
	t_2Dvector	*vector2D_start;
	t_2Dvector	*vector2D_end;

	i = 0;
	vector3D_start = NULL;
	vector3D_end = NULL;
	if (splitted_line1)
	{
		while (splitted_line1[(int)i])
		{
			vector3D_start = new_3Dvector(i, j, ft_atoi(splitted_line1[i]));
			printf("start->x = %f, start->y = %f, start->z = %f\n", vector3D_start->x, vector3D_start->y, vector3D_start->z);
			vector2D_start = vector3D_to_2D(vector3D_start);
			printf("start->x = %f, start->y = %f\n", vector2D_start->x, vector2D_start->y);
			if (i != get_charss_len(splitted_line1) - 1)
			{
				z = ft_atoi(splitted_line1[(int)i + 1]);
				vector3D_end = new_3Dvector(i + 1, j, z);
				vector2D_end = vector3D_to_2D(vector3D_end);
				ft_draw_line(mlx, win, vector2D_start, vector2D_end);
				free(vector3D_end);
				free(vector2D_end);
			}
			if (splitted_line2)
			{
				z = ft_atoi(splitted_line1[(int)i]);
				vector3D_end = new_3Dvector(i, j + 1, z);
				vector2D_end = vector3D_to_2D(vector3D_end);
				ft_draw_line(mlx, win, vector2D_start, vector2D_end);
				free(vector3D_end);
				free(vector2D_end);
			}
			free(vector3D_start);
			free(vector2D_start);
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	int			fd;

	if (argc != 2)
	{
		ft_putstr("Usage : fdf <file1>\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1 )
	{
		strerror(errno);
		return (0);
	}

	mlx = mlx_init();
	win = mlx_new_window(mlx, 4242, 4242, "FDF");
	fdf(fd, mlx, win);
	while(1);
	return (0);
}
