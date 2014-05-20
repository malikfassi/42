/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 17:43:38 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/16 19:48:32 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>

static void	create_img(t_env *env)
{
	env->img = mlx_new_image(env->mlx, MAP_WIDTH, MAP_HEIGHT);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);
}

static void	put_pixel_to_img(t_env *e, int x, int y)
{
	((char *)(e->data))[(y * e->size_line) + x * (e->bpp / 8)  + 2] = mlx_get_color_value(e->mlx, RED);
	((char *)(e->data))[(y * e->size_line) + x * (e->bpp / 8) + 1] = mlx_get_color_value(e->mlx, GREEN);
	((char *)(e->data))[(y * e->size_line) + x * (e->bpp / 8)] = mlx_get_color_value(e->mlx, BLUE);
}

void		draw_line(t_env *env, int curr_x)
{
	int		count = env->draw_start;
	
	printf("je draw de %i, a %i\n", env->draw_start, env->draw_end);
	create_img(env);
	while (count != env->draw_end)
	{
		put_pixel_to_img(env, curr_x, count);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 300, 300);
		count++;
	}
}
