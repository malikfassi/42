/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:55:32 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/16 12:16:50 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_h
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>


# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# define INIT_POS_X 1
# define INIT_POS_Y 1
# define DIR_X 0
# define DIR_Y 1
# define PLANE_Y 0.66
# define PLANE_X 0
# define RED 255
# define BLUE 75
# define GREEN 0

typedef struct		s_dble_vect2D
{
	double	x;
	double	y;
}					t_dble_vect2D;

typedef struct		s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*data;
	int					bpp;
	int					size_line;
	int					endian;
	struct s_player		*player;
	double				time;
	double				oldtime;
	struct s_int_vect2D	*step;
	int					hit;
	int					side;
	int					draw_start;
	int					draw_end;
}					t_env;

typedef struct		s_player
{
	struct s_dble_vect2D 	*pos;
	struct s_dble_vect2D	*plane;
	struct s_dble_vect2D	*dir;
	double					camerax;
	struct s_dble_vect2D	*r_pos;
	struct s_dble_vect2D	*r_dir;
	struct s_int_vect2D		*map_pos;
	struct s_dble_vect2D	*dist_to_wall;
	struct s_dble_vect2D	*dist2_wall;
	double					wall_length;
	int						wall_height;
}					t_player;


typedef struct		s_int_vect2D
{
	int	x;
	int	y;
}					t_int_vect2D;

t_env			*new_env();
t_player		*new_player();
t_int_vect2D	*new_int2Dvect(int x, int y);
t_dble_vect2D	*new_dble2Dvect(double x, double y);
void			check_dir_x(t_env *env);
void			check_dir_y(t_env *env);
void			DDA(t_env *env, int map[][MAP_WIDTH]);
void			set_wall(t_env  *env);
void			draw_line(t_env *env, int curr_x);
#endif
