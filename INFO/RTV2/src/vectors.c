/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 14:07:04 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/02/14 18:05:02 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_V3D_double	*new_V3D_double(double x, double y, double z)
{
	t_V3D_double	*vector;

	vector = (t_V3D_double *)malloc(sizeof(t_V3D_double));
	if (vector)
	{
		vector->x = x;
		vector->y = y;
		vector->z = z;
	}
	return (vector);
}

t_V3D_float		*new_V3D_float(float x, float y, float z)
{
	t_V3D_float	*vector;

	vector = (t_V3D_float *)malloc(sizeof(t_V3D_float));
	if (vector)
	{
		vector->x = x;
		vector->y = y;
		vector->z = z;
	}
	return (vector);
}

t_cam	*new_cam(t_V3D_double *orig, t_V3D_double *target, double focal_len)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (cam)
	{
		cam->orig = (orig) ? orig : new_V3D_double(0, 0, 0);
		cam->target = (target) ? target : new_V3D_double(0, 0, 0);
		cam->focal_len = (focal_len) ? focal_len : -RES_X / (2 * tan(FOV / 2));
		if (!cam->target || !cam->orig || !cam->direction)
		{
			ft_putstr_fd("malloc_failed\n", 2);
			free(&cam);
			return (NULL);
		}
	}
	return (cam);
}

t_ray	*new_ray(t_V3D_double *orig, t_V3D_double *dir)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray)
	{
		ray->orig = (orig) ? orig : new_V3D_double(0, 0, 0);
		ray->dir = (dir) ? dir : new_V3D_double(0, 0, 0);
		if (!ray->dir || !ray->orig)
		{
			ft_putstr_fd("malloc_failed\n", 2);
			free(&ray);
			return (NULL);
		}
	}
	return (ray);
}

t_sphere	*new_sphere(t_V3D_double *pos, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere)
	{
		sphere->pos = (pos) ? pos : new_V3D_double(0,0,0);
		sphere->radius = radius;
		if (!sphere->pos)
		{
			ft_putstr_fd("malloc failed\n", 2);
			free(&sphere);
			return (NULL);
		}
	}
	return (sphere);
}

void	normalize_vector(t_V3D_double *vector)
{
	double	norme;

	norme = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
	printf("norme = %f\n", norme);
//	norme = pow(norme, -1);
	vector->x /= norme;
	vector->y /= norme;
	vector->z /= norme;
}

double	vect_mult(t_V3D_double *vectA, t_V3D_double *vectB)
{
	return (vectA->x * vectB->x + vectA->y * vectB->y + vectA->z * vectB->z);
}

t_V3D_double	*vect_copy(t_V3D_double	*vect)
{
	t_V3D_double	*new_vect;

	new_vect = new_V3D_double(vect->x, vect->y, vect->z);
	return (new_vect);
}

t_V3D_double	*vect_sub(t_V3D_double *vectA, t_V3D_double *vectB)
{
	t_V3D_double	*new_vect;
	double			x;
	double			y;
	double			z;

	x = vectA->x - vectB->x;
	y = vectA->y - vectB->y;
	z = vectA->z - vectB->z;
	new_vect = new_V3D_double(x, y, z);
	return (new_vect);
}
