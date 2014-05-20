/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 13:37:59 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/15 13:47:37 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>



t_player	*get_player(t_mlx *env)
{
	return (env->player);
}

t_dble_vect2D	*get_pos(t_mlx *env)
{
	return (env->player->pos);
}

t_dble_vect2D	*get_plane(t_mlx *env)
{
	return (env->player->plane);
}

t_dble_vect2D	*get_dir(t_mlx *env)
{
	return (env->player->dir);
}

t_dble_vect2D	*get_ray_pos(t_mlx *env)
{
	return (env->player->ray_pos);
}

t_dble_vect2D	*get_ray_dir(t_mlx *env)
{
	return (env->player->ray_dir);
}

t_dble_vect2D	*get_dist_to_wall(t_mlx *env)
{
	return (env->player->dist_to_wall);
}

t_dble_vect2D	*get_next_dist_to_wall(t_mlx *env)
{
	return (env->player->next_dist_to_wall);
}

t_int_vect2D	*get_map_pos(t_mlx *env)
{
	return (env->player->map_pos);
}

double	get_camerax(t_mlx *env)
{
	return (env->player->camera_x);
}

double	get_wall_len(t_mlx *env)
{
	return (env->player->wall_length);
}
