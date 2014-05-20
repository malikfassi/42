/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:00:09 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/14 20:14:30 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_mlx	*new_env()
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env *));
	if (env)
	{
		env->mlx = mlx_init();
		env->win = mlx_new_window(env->mlx, MAP_HEIGHT, MAP_WIDTH, "wolf3d");
		env->player = new_player();
		if (!player)
		{
			free(env);
			return (NULL);
		}
		env->time = 0;
		env->old_time = 0;
	}
	return (mlx_body);
}
