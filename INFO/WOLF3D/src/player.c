/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:23:37 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/14 21:18:12 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_player	*new_player()
{
	t_player	*player;
	
	player = (t_player *)malloc(sizeof(player *));
	if (player)
	{
		player->x = INIT_POS_X;
		player->y = INIT_POS_Y;
		player->plane_x = PLANE_X;
		player->plane_y = PLANE_Y;
		player->dir_x = DIR_X;
		player->dir_y = DIR_Y;
		player->camera_x = 0;
		player->ray_pos_x = 0;
		player->ray_pox_y = 0;
		player->ray_dir_x = 0;
		player->ray_dir_y = 0;
		player->map_x = 0;
		player->map_y = 0;
		player->dist_to_wall_x = 0;
		player->dist_to_wall_y = 0;
		player->next_dist_to_wall_x = 0;
		player->next_dist_to_wall_y = 0;
		player->wall_length = 0;
	}
	return (player);
}
