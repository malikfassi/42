/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:30:21 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/16 19:46:36 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3D.h>

void	DDA(t_env *env, int map[][MAP_WIDTH])
{
	t_player	*p;

	p = env->player;
	while (env->hit == 0)
	{
		if (p->dist_to_wall->x < p->dist_to_wall->y)
		{
			p->dist_to_wall->x += p->dist2_wall->x;
			p->map_pos->x += env->step->x;
			env->side = 0;
		}
		else
		{
			p->dist_to_wall->y += p->dist2_wall->y;
			p->map_pos->y += env->step->y;
			env->side = 1;
		}
		if (map[p->map_pos->x][p->map_pos->y] > 0)
			env->hit = 1;
	}
}
