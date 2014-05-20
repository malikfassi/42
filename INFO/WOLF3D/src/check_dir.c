/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:02:46 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/16 12:16:48 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	check_dir_x(t_env *env)
{
	t_player		*p;

	p = env->player;
	if (p->r_dir->x < 0)
	{
		env->step->x = -1;
		p->dist_to_wall->x = (p->r_pos->x - p->map_pos->x) * p->dist2_wall->x;
	}
	else
	{
		env->step->x = 1;
		p->dist_to_wall->x = (p->map_pos->x + 1.0 - p->r_pos->x) * p->dist2_wall->x;
	}
}

void	check_dir_y(t_env *env)
{
	t_player		*p;

	p = env->player;
	if (p->r_dir->y < 0)
	{
		env->step->y = -1;
		p->dist_to_wall->y = (p->r_pos->y - p->map_pos->y) * p->dist2_wall->y;
	}
	else
	{
		env->step->y = 1;
		p->dist_to_wall->y = (p->map_pos->y + 1.0 - p->r_pos->y) * p->dist2_wall->y;
	}
}
