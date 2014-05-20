/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 21:18:20 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/16 11:56:16 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_env	*new_env()
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (env)
	{
		env->mlx = mlx_init();
		env->win = mlx_new_window(env->mlx, MAP_HEIGHT * 30, MAP_WIDTH * 30, "wolf3d");
		env->player = new_player();
		env->time = 0;
		env->oldtime = 0;
		env->step = new_int2Dvect(0,0);
		if (! (env->step && env->player))
		{
			//free(player);
			free(env);
			return (NULL);
		}
		env->hit = 0;
		env->side = 0;
		env->draw_start = 0;
		env->draw_end = 0;
	}
	return (env);
}

t_player	*new_player()
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player)
	{
		player->pos = new_dble2Dvect(INIT_POS_X, INIT_POS_Y);
		player->plane = new_dble2Dvect(PLANE_X, PLANE_Y);
		player->dir = new_dble2Dvect(DIR_X, DIR_Y);
		player->camerax = 0;
		player->r_pos = new_dble2Dvect(0,0);
		player->r_dir = new_dble2Dvect(0,0);
		player->map_pos = new_int2Dvect(0,0);
		player->dist_to_wall = new_dble2Dvect(0,0);
		player->dist2_wall = new_dble2Dvect(0,0);
		player->wall_length = 0;
		player->wall_height = 0;
		if ( !(player->pos && player->plane && player->dir && player->r_pos 
						   && player->r_dir && player->map_pos 
						   && player->dist_to_wall 
						   && player->dist2_wall))
			return (NULL);
	}
	return (player);
}

t_int_vect2D	*new_int2Dvect(int x, int y)
{
	t_int_vect2D	*vect;

	vect = (t_int_vect2D *)malloc(sizeof(t_int_vect2D));
	if (vect)
	{
		vect->x = x;
		vect->y = y;
	}
	return (vect);
}

t_dble_vect2D	*new_dble2Dvect(double x, double y)
{
	t_dble_vect2D	*vect;

	vect = (t_dble_vect2D *)malloc(sizeof(t_dble_vect2D));
	if (vect)
	{
		vect->x = x;
		vect->y = y;
	}
	return (vect);
}
