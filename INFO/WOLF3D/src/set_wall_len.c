/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:17:57 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/16 20:32:25 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	set_wall(t_env	*env)
{
	t_player	*p;

	p = env->player;
	if (env->side == 0)
	{
		p->wall_length = p->map_pos->x - p->r_pos->x; 
		p->wall_length += (1 - env->step->x) / 2;
		p->wall_length /= p->r_dir->x;
		p->wall_length = fabs(p->wall_length);
	}
	else
	{
		printf("map_pos = (%i, %i) ; r_pos = (%f, %f) ; step = (%i, %i) ; r_dir = (%f, %f) \n", p->map_pos->x, p->map_pos->y, p->r_pos->x, p->r_pos->y, env->step->x, env->step->y, p->r_dir->x, p->r_dir->y);


		p->wall_length = p->map_pos->y - p->r_pos->y;
		p->wall_length += (1 - env->step->y) / 2;
		p->wall_length /= p->r_dir->y;
		p->wall_length = fabs(p->wall_length);
	}
	printf("%f\n", p->wall_length);
	p->wall_height = fabs((int)(MAP_HEIGHT / p->wall_length));
	printf("%i\n", p->wall_height);
	env->draw_start = -(p->wall_height / 2) + MAP_HEIGHT / 2;
	if (env->draw_start < 0)
		env->draw_start = 0;
	env->draw_end = p->wall_height / 2 + MAP_HEIGHT / 2;
	if (env->draw_end >= MAP_HEIGHT)
		env->draw_end = MAP_HEIGHT - 1;
	printf("%i, %i, %i, %f, %i\n", env->draw_start, env->draw_end, p->wall_height, p->wall_length, env->side);
}
