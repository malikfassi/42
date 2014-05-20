/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 13:31:40 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/02/14 17:41:41 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define RES_X 640.0
# define RES_Y 480.0
# define COEF 200000000
#define PI (3.141592653589793)


# define FOV 45.0
# define CAMPOS_X 0
# define CAMPOS_Y 1.8
# define CAMPOS_Z 10.0
# define CAMDIR_X 0.0
# define CAMDIR_Y 3.0
# define CAMDIR_Z 0.0

# define LIGHT_X -30.0
# define LIGHT_Y -10.0
# define LIGHT_Z 20.0

# define OBJ1POS_X 0.0
# define OBJ1POS_Y 3.5
# define OBJ1POS_Z -3.0
# define OBJ1COL_X 155.0
# define OBJ1COL_Y 200.0
# define OBJ1COL_Z 155.0
# define OBJ1SPEC 0.2
# define OBJ1LAMB 0.7
# define OBJ1AMB 0.1
# define OBJ1RAD 3.0

# define OBJ2POS_X -4.0
# define OBJ2POS_Y 2.0
# define OBJ2POS_Z -1.0
# define OBJ2COL_X 155.0
# define OBJ2COL_Y 155.0
# define OBJ2COL_Z 155.0
# define OBJ2SPEC 0.1
# define OBJ2LAMB 0.9
# define OBJ2AMB 0.0
# define OBJ2RAD 0.2

# define OBJ3POS_X -4.0
# define OBJ3POS_Y 3.0
# define OBJ3POS_Z -1.0
# define OBJ3COL_X 255.0
# define OBJ3COL_Y 255.0
# define OBJ3COL_Z 255.0
# define OBJ3SPEC 0.2
# define OBJ3LAMB 0.7
# define OBJ3AMB 0.1
# define OBJ3RAD 0.1

# define LIGHTS scene->lights
# define CAM scene->cam
# define OBJ scene->objects

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

typedef struct	s_cam
{
	t_V3D_double	*pos;
	t_V3D_double	*dir;
	double			fov;
}				t_cam;

typedef struct			s_objects
{
	char				*type;
	t_V3D_double		*pos;
	t_V3D_double		*color;
	double				specular;
	double				lambert;
	double				ambient;
	double				radius;
	struct s_objects	*next;
}						t_objects;

typedef struct		s_scene
{
	t_cam			*cam;
	t_V3D_double	**lights;
	t_objects		*objects;
}					t_scene;

typedef struct		s_env
{
	t_V3D_double    *UP;
	t_V3D_double    *ZERO;
	t_V3D_double    *WHITE;
	double          fov_radians;
	double          heightwidthratio;
	double          halfwidth;
	double          halfheight;
	double			camerawidth;
	double			cameraheight;
	double			pixelwidth;
	double			pixelheight;
}					t_env;

typedef struct		s_ray
{
	t_V3D_double	*orig;
	t_V3D_double	*vector;
}					t_ray;

typedef struct		s_closest
{
	t_objects		*obj;
	double			dist;
}					t_closest;

t_objects		*new_object(t_V3D_double *pos, t_V3D_double *color, double *spec);
t_scene			*new_scene(t_cam *cam, t_V3D_double **lights, t_objects *objects);
t_cam			*new_cam(t_V3D_double *pos, t_V3D_double *dir, double fov);
t_V3D_double	*vect_add3(t_V3D_double *a, t_V3D_double *b, t_V3D_double *c);
t_V3D_double	*new_V3D_double(double x, double y, double z);
t_V3D_double	*vect_copy(t_V3D_double *vect);
t_V3D_double	*vect_sub(t_V3D_double *vectA, t_V3D_double *vectB);
double			vect_mult(t_V3D_double *vectA, t_V3D_double *vectB);
t_V3D_double	*cross_prod(t_V3D_double *vectA, t_V3D_double * vectB);
void			normalize_vector(t_V3D_double *vector);
t_V3D_double	*vect_add(t_V3D_double *a, t_V3D_double *b);
t_V3D_double	*scale(t_V3D_double *vect, double nb);
t_closest		*intersect_scene(t_ray *ray, t_scene *scene);
t_V3D_double	*surface(t_ray *ray, t_scene *scene, t_objects *object, t_V3D_double *inter, t_V3D_double *normal, double depth);
t_V3D_double	*sphere_normal(t_objects *sphere, t_V3D_double *pos);
t_closest		*new_closest();
double			sphere_intersection(t_objects *sphere, t_ray *ray);
int				is_light_visible(t_V3D_double *inter, t_scene *scene, t_V3D_double *light);
t_ray			*new_ray();
t_V3D_double	*reflect_through(t_V3D_double *a, t_V3D_double *normal);


#endif


