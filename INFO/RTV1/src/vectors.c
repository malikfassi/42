/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 14:07:04 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/02/14 17:41:15 by mfassi-f         ###   ########.fr       */
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

t_cam	*new_cam(t_V3D_double *pos, t_V3D_double *dir, double fov)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (cam)
	{
		cam->pos = (pos) ? pos : new_V3D_double(CAMPOS_X, CAMPOS_Y, CAMPOS_Z);
		cam->dir = (dir) ? dir : new_V3D_double(CAMDIR_X, CAMDIR_Y, CAMDIR_Z);
		cam->fov = (fov > 0) ? fov : FOV;
		if (!cam->pos || !cam->dir)
		{
			ft_putstr_fd("malloc_failed\n", 2);
			free(&cam);
			return (NULL);
		}
	}
	return (cam);
}


t_objects	*new_object(t_V3D_double *pos, t_V3D_double *color, double *spec)
{
	t_objects	*object;

	object = (t_objects *)malloc(sizeof(t_objects));
	if (object)
	{
		object->type = "sphere";
		object->pos = (pos) ? pos : new_V3D_double(0,0,0);
		object->color = (color) ? color : new_V3D_double(255,255,255);
		object->specular = (spec) ? spec[0] : 0;
		object->lambert = (spec) ? spec[1] : 0;
		object->ambient = (spec) ? spec[2] : 0;
		object->radius = (spec) ? spec[3] : 0;
		object->next = NULL;
		if (!object->pos || !object->color)
		{
			ft_putstr_fd("malloc_failed\n", 2);
			free(&object);
			return (NULL);
		}
	}
	return (object);
}

t_scene	*new_scene(t_cam *cam, t_V3D_double	**lights, t_objects	*objects)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (scene)
	{
		scene->cam = (cam) ? cam : new_cam(NULL, NULL, 0);
		scene->lights = (lights) ? lights : NULL;
		if (!scene->lights)
		{
			scene->lights = (t_V3D_double **)malloc(sizeof(t_V3D_double *) * 2);
			scene->lights[0] = new_V3D_double(LIGHT_X, LIGHT_Y, LIGHT_Z);
			scene->lights[1] = NULL;
		}
		scene->objects = (objects) ? objects : new_object(NULL, NULL, NULL);
		if (!scene->cam || !scene->lights || !scene->objects)
		{
			ft_putstr_fd("malloc_failed\n", 2);
			free(&scene);
			return (NULL);
		}
	}
	return (scene);
}

t_ray	*new_ray()
{
	t_ray	*new_ray;

	new_ray = (t_ray *)ft_memalloc(sizeof(t_ray *));
	return (new_ray);
}

t_closest	*new_closest()
{
	t_closest	*new_closest;

	new_closest = (t_closest *)malloc(sizeof(t_closest *));
	if (new_closest)
	{
		new_closest->dist = -1;
		new_closest->obj = NULL;
	}
	return (new_closest);
}

void	normalize_vector(t_V3D_double *vector)
{
	double	norme;

	norme = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
	vector->x /= norme;
	vector->y /= norme;
	vector->z /= norme;
}

double	vect_mult(t_V3D_double *vectA, t_V3D_double *vectB)
{
	return (vectA->x * vectB->x + vectA->y * vectB->y + vectA->z * vectB->z);
}

t_V3D_double	*scale(t_V3D_double *vect, double nb)
{
	t_V3D_double	*new_vect;
	new_vect = new_V3D_double(vect->x * nb, vect->y * nb, vect->z * nb);
	return (new_vect);
}

t_V3D_double	*vect_add3(t_V3D_double *a, t_V3D_double *b, t_V3D_double *c)
{
	t_V3D_double	*new_vect;
	new_vect = new_V3D_double(a->x + b->x + c->x, a->y + b->y + c->y, a->z + b->z + c->z);
	return (new_vect);
}

t_V3D_double	*vect_add(t_V3D_double *a, t_V3D_double *b)
{
	t_V3D_double	*new_vect;
	new_vect = new_V3D_double(a->x + b->x, a->y + b->y, a->z + b->z);
	return (new_vect);
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

t_V3D_double	*cross_prod(t_V3D_double *vectA, t_V3D_double * vectB)
{
	t_V3D_double	*vect;

	vect = new_V3D_double(0, 0, 0);
	vect->x = vectA->y * vectB->z - vectA->z * vectB->y;
	vect->y = vectA->z * vectB->x - vectA->x * vectB->z;
	vect->z = vectA->x * vectB->y - vectA->y * vectB->x;
	return (vect);
}
