/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 13:31:40 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/29 13:20:09 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define FOV 45
# define RES_X 640
# define RES_Y 480
# define COEF 200000000
# define CAM_X 0
# define CAM_Y 1.8
# define CAM_Z 10


# include <libft.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

#include <stdio.h>
typedef struct	s_V3D_double
{
	double	x;
	double	y;
	double	z;
}				t_V3D_double;

typedef struct	s_V3D_float
{
	float	x;
	float	y;
	float	z;
}				t_V3D_float;

typedef struct	s_cam
{
	t_V3D_double	*orig;
	t_V3D_double	*target;
	double			focal_len;
	t_V3D_double	*direction;
}				t_cam;

typedef struct	s_ray
{
	t_V3D_double	*orig;
	t_V3D_double	*dir;
}				t_ray;

typedef struct	s_sphere
{
	t_V3D_double	*pos;
	double			radius;
}				t_sphere;



t_V3D_double    *new_V3D_double(double x, double y, double z);
t_cam   *new_cam(t_V3D_double *orig, t_V3D_double *target, double focal_len);
t_ray   *new_ray(t_V3D_double *orig, t_V3D_double *dir);
t_sphere    *new_sphere(t_V3D_double *pos, double radius);
void    normalize_vector(t_V3D_double *vector);
double  vect_mult(t_V3D_double *vectA, t_V3D_double *vectB);
t_V3D_double    *vect_copy(t_V3D_double *vect);
t_V3D_double    *vect_sub(t_V3D_double *vectA, t_V3D_double *vectB);

#endif


