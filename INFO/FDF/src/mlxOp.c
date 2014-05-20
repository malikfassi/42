/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxOp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:10:36 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/28 19:46:17 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxOp.h>
#include <unistd.h>
#include <ft_math.h>
#include <vector.h>
#include <stdio.h>

void	draw_horizontal_lines(t_2Dvector *start, double nb, void *mlx, void *win)
{
	double x;
	double y;

	y = start->y;
	while (y < start->y + nb)
	{
		x = start->x;
		while (x < 1100)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_vertical_lines(t_2Dvector *start, t_2Dvector *dim, void *mlx, void *win)
{
	double	x;
	double	y;

	y = start->y;
	while (y < start->y + dim->y)
	{
		x = start->x;
		while (x <= 1100)
		{
			mlx_pixel_put(mlx, win, x++, y, 0xFFFFFF);
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			x += dim->x;
		}
		y++;
	}
}

void	ft_draw_line(void *mlx, void *win, t_2Dvector *point_a, t_2Dvector *point_b)
{
	t_2Dvector	*diff;
	t_2Dvector	*inc;
	t_2Dvector	*final;
	double		i;
	double		cumul;

	final = new_2Dvector(point_a->x, point_a->y);
	diff = new_2Dvector(point_b->x - point_a->x, point_b->y - point_a->x);
	inc = new_2Dvector(0,0);
	i = 1;
	inc->x = (diff->x > 0) ? 1 : -1;
	inc->y = (diff->y > 0) ? 1 : -1;
	diff->x = ft_abs(diff->x);
	diff->y = ft_abs(diff->y);
	printf("1\n");
	printf("mlx = %p, win = %p, x = %f, y = %f\n", mlx, win, final->x + OFFSETX, final->y + OFFSETY);
	mlx_pixel_put(mlx, win, final->x + OFFSETX, final->y + OFFSETY, 0x00FF00);
	printf("2\n");
	if (diff->x > diff->y)
	{
		cumul = diff->x / 2;
		while (i <= diff->x)
		{
			final->x += inc->x;
			cumul += diff->y;
			if (cumul >= diff->x)
			{
				cumul -= diff->x;
				final->y += inc->y;
			}
			mlx_pixel_put(mlx, win, final->x + OFFSETX, final->y + OFFSETY, 0xFFFFFF);
			i++;
		}
	}
	else
	{
		cumul = diff->y / 2;
		while (i <= diff->y)
		{
			final->y+= inc->y;
			cumul += diff->x;
			if (cumul >= diff->y)
			{
				cumul-= diff->y;
				final->x += inc->x;
			}
			mlx_pixel_put(mlx, win, final->x + OFFSETX, final->y + OFFSETY, 0xFFFFFF);
			i++;
		}
	}
}
