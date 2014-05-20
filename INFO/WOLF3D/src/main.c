/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:34:18 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/16 11:54:00 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

#include <stdlib.h>
#include <unistd.h>
int	main()
{
	int	map[][MAP_WIDTH] = { 
						 {1,1,1,1,1,1,1,1,1,1},
						 {1,0,0,0,0,0,0,0,0,1},
						 {1,0,0,0,0,0,0,0,0,1},
						 {1,0,0,0,0,0,0,0,0,1},
						 {1,1,0,1,1,1,1,0,0,1},
						 {1,0,0,0,0,0,1,0,0,1},
						 {1,0,0,0,0,0,1,0,0,1},
						 {1,1,1,1,1,0,1,0,0,1},
						 {1,0,0,0,0,0,0,0,1,1},
						 {1,1,1,1,1,1,1,1,1,1}
					   };
	t_env		*env;
	int			curr_x;
	t_player	*p;

	curr_x = 0;
	env = new_env();
	p = env->player;
	if (!env)
	{
		perror("malloc failed");
		return (1);
	}
	while (curr_x < MAP_WIDTH)
	{	
		p->camerax = 2 * curr_x / (double)MAP_WIDTH - 1;
		p->r_pos->x = p->pos->x;
		p->r_pos->y = p->pos->y;
		p->r_dir->x = p->dir->x + p->plane->x * p->camerax;
		p->r_dir->y = p->dir->y + p->plane->y * p->camerax;
		p->map_pos->x = (int)p->r_pos->x;
		p->map_pos->y = (int)p->r_pos->y;
		p->dist2_wall->x = sqrt(1 + pow(p->r_dir->y, 2) / pow(p->r_dir->x, 2));
		p->dist2_wall->x = sqrt(1 + pow(p->r_dir->x, 2) / pow(p->r_dir->y, 2));
		env->hit = 0;
		check_dir_x(env);
		check_dir_y(env);
		DDA(env, map);
		set_wall(env);
		draw_line(env, curr_x);
		curr_x++;
	}
	sleep(10);
	return (0);
}
