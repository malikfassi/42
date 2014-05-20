/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 13:58:39 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/02/15 16:59:05 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>


#include <stdio.h>

void	print_vector(t_V3D_double	*vect)
{
	printf("(%f, %f, %f)\n", vect->x, vect->y, vect->z);
}

t_objects	*objects_creation(void)
{
	double		spec[4] = {OBJ1SPEC, OBJ1LAMB, OBJ1AMB, OBJ1RAD};
	t_objects	*objects;

	objects = new_object(new_V3D_double(OBJ1POS_X, OBJ1POS_Y, OBJ1POS_Z), 
			new_V3D_double(OBJ1COL_X, OBJ1COL_Y, OBJ1COL_Z), spec);
	spec[0] = OBJ2SPEC;
	spec[1] = OBJ2LAMB;
	spec[2] = OBJ2AMB;
	spec[3] = OBJ2RAD;
	objects->next = new_object(new_V3D_double(OBJ2POS_X, OBJ2POS_Y, OBJ2POS_Z), 
			new_V3D_double(OBJ2COL_X, OBJ2COL_Y, OBJ2COL_Z), spec);
	spec[0] = OBJ3SPEC;
	spec[1] = OBJ3LAMB;
	spec[2] = OBJ3AMB;
	spec[3] = OBJ3RAD;
	objects->next->next = 
		new_object(new_V3D_double(OBJ3POS_X, OBJ3POS_Y, OBJ3POS_Z), 
				new_V3D_double(OBJ3COL_X, OBJ3COL_Y, OBJ3COL_Z), spec);
	return (objects);
}

t_env	*init_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env *));
	env->UP = new_V3D_double(0, 1, 0);
	env->ZERO = new_V3D_double(0, 0, 0);
	env->WHITE = new_V3D_double(255, 255, 255);
	return (env);
}

double	join_color(t_V3D_double *color)
{
	return (1000000 * color->x + 1000 * color->y + color->z);
}



t_V3D_double	*trace(t_ray *ray, t_scene *scene, int depth)
{
	t_closest		*closest;
	t_V3D_double	*inter;
	t_objects		*obj;

	if (depth > 3)
		return (NULL);
	closest = intersect_scene(ray, scene);
	if (closest->dist == -1)
	{
		return (new_V3D_double(255, 255, 255));
	}
	printf("closest->dist = %f\n", closest->dist);
	inter = vect_add(ray->orig, scale(ray->vector, closest->dist));
	obj = closest->obj;
	printf("surface\n");
	return (surface(ray, scene, obj, inter, sphere_normal(obj, inter), depth));
}

t_closest	*intersect_scene(t_ray *ray, t_scene *scene)
{
	t_closest	*closest;
	t_objects	*objects;
	double		dist;

	closest = new_closest();
	objects = scene->objects;
	while (objects)
	{
		dist = sphere_intersection(objects, ray);
		if (dist > 0 && dist < closest->dist)
		{
			printf("yeah\n");
			closest->dist = dist;
			closest->obj = objects;
		}
		objects = objects->next;
	}
	return (closest);
}

double	sphere_intersection(t_objects *sphere, t_ray *ray)
{
	t_V3D_double	*eye;
	double			dist;
	double			cam2center;
	double			delta;

//	printf("sphere->pos : ");
//	print_vector(sphere->pos);
//	printf("sphere->radius : %f\n", sphere->radius);
//	printf("ray->orig : ");
//	print_vector(ray->orig);
//	printf("ray->vector : ");
//	print_vector(ray->vector);
	eye = vect_sub(sphere->pos, ray->orig);
//	printf("eye : ");
//	print_vector(eye);
	dist = vect_mult(eye, ray->vector);
//	printf("dist = %f\n", dist);
	cam2center = vect_mult(eye, eye);
//	printf("cam2center = %f\n", cam2center);
	delta = pow(sphere->radius, 2) - cam2center + pow(dist, 2);
//	printf("delta = %f, sphere->raduis = %f, cam2center = %f, dist = %f\n", delta, sphere->radius, cam2center, dist);
	if (delta < 0)
		return (0);

	return (dist - sqrt(delta));
}

t_V3D_double	*sphere_normal(t_objects *sphere, t_V3D_double *pos)
{
	t_V3D_double	*normal;

	printf("sphere->pos = %p\n",sphere);
	normal = vect_sub(pos, sphere->pos);
	printf("normal\n");
	normalize_vector(normal);
	printf("normal\n");
	return (normal);
}

double	ft_min(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}

t_V3D_double	*surface(t_ray *ray, t_scene *scene, t_objects *object, t_V3D_double *inter, t_V3D_double *normal, double depth)
{
	double			lambert_amount;
	t_V3D_double	*b;
	t_V3D_double	*c;
	t_V3D_double	*light_pos;
	int				i;
	double			contr;
	t_V3D_double	*tmp;
	t_V3D_double	*tmp2;
	t_ray			*reflected_ray;
	t_V3D_double	*reflected_color;

	printf("specular\n");
	lambert_amount = 0;
	b = object->color;
	c = new_V3D_double(0, 0, 0);
	if (object->lambert)
	{
		i = 0;
		while (scene->lights[i])
		{
			light_pos = scene->lights[i];
			if (!is_light_visible(inter, scene, light_pos))
				continue ;
			tmp = vect_sub(light_pos, inter);
			normalize_vector(tmp);
			contr = vect_mult(tmp, normal);
			free(tmp);
			if (contr > 0)
				lambert_amount += contr;
			i++;
		}
	}
	if (object->specular)
	{
		reflected_ray = new_ray();
		reflected_ray->orig = inter;
		reflected_ray->vector = reflect_through(ray->vector, normal);
		reflected_color = trace(reflected_ray, scene, ++depth);
		if (reflected_color)
		{
			tmp = scale(reflected_color, object->specular);
			c = vect_add(c, tmp);
			free(tmp);
		}
	}
	lambert_amount = ft_min(1, lambert_amount);
	printf("specular1\n");
	tmp = scale(b, lambert_amount * object->lambert);
	printf("specular2\n");
	tmp2 = scale(b, object->ambient);
	printf("specular3\n");
	b = vect_add3(c, tmp, tmp2);
	printf("specular4\n");
	free(tmp);
	printf("specular5\n");
	free(tmp2);
	printf("specular6\n");
	printf("b = %p\n", b);
	return (b);
}

int		is_light_visible(t_V3D_double *inter, t_scene *scene, t_V3D_double *light)
{
	t_closest	*closest;
	t_ray		*ray;
	int			res;

	ray = new_ray();
	ray->orig = inter;
	ray->vector = vect_sub(inter, light);
	normalize_vector(ray->vector);
	closest = intersect_scene(ray, scene);
	res = closest->dist > -0.005;
	free(closest);//djufdk
	return (res);
}


t_V3D_double	*reflect_through(t_V3D_double *a, t_V3D_double *normal)
{
	t_V3D_double	*res;
	t_V3D_double	*tmp;
	t_V3D_double	*tmp2;

	tmp = scale(normal, vect_mult(a, normal));
	tmp2 = scale(tmp, 2.0);
	res = vect_sub(tmp2, a);
	free(tmp);
	free(tmp2);
	return (res);
}


int	main(void)
{
	t_objects		*objects;
	t_scene			*scene;
	int				pixel_x;
	int				pixel_y;
	void			*mlx;
	void			*win;
	t_V3D_double	*eye;
	t_V3D_double	*vpRight;
	t_V3D_double	*vpUP;
	t_env			*env;
	t_V3D_double	*color;
	t_V3D_double	*xcomp;
	t_V3D_double	*ycomp;
	t_ray			*ray;

	env = init_env();
	objects = objects_creation();
	scene = new_scene(NULL, NULL, objects);
	eye = vect_sub(CAM->dir, CAM->pos);
	normalize_vector(eye);
	vpRight = cross_prod(eye, env->UP);
	normalize_vector(vpRight);
	vpUP = cross_prod(vpRight, eye);
	normalize_vector(vpUP);
	env->fov_radians = PI * (scene->cam->fov / 2) / 180;
	//printf("fov_radians = %f\n", env->fov_radians);
	env->heightwidthratio = RES_Y / RES_X;
//	printf("heightwidthratio = %f\n", env->heightwidthratio);
	env->halfwidth = tan(env->fov_radians);
//	printf("halfwidth = %f\n", env->halfwidth);
	env->halfheight = env->heightwidthratio * env->halfwidth;
//	printf("halfheight = %f\n", env->halfheight);
	env->cameraheight = env->halfheight * 2;
//	printf("cameraheight = %f\n", env->cameraheight);
	env->camerawidth = env->halfwidth * 2;
//	printf("camerawidtf = %f\n", env->camerawidth);
	env->pixelheight = env->cameraheight / (RES_Y - 1) * 2;
//	printf("pixelheight = %f\n", env->pixelheight);
	env->pixelwidth = env->camerawidth / (RES_X - 1) * 2;
//	printf("pixelwidth = %f\n", env->pixelwidth);
	ray = new_ray();
	ray->vector = new_V3D_double(0,0,0);
	ray->orig = vect_copy(scene->cam->pos);
	pixel_x = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, RES_X, RES_Y, "RTV1");
	color = new_V3D_double(0, 0, 0);
	int i = 0;
	while (pixel_x < RES_X)
	{
		pixel_y = 0;
		while (pixel_y < RES_Y)
		{
			xcomp = scale(vpRight, (pixel_x * env->pixelwidth) - env->halfwidth);
			ycomp = scale(vpUP, (pixel_y * env->pixelheight) - env->halfheight);
			free(ray->vector);
			ray->vector = vect_add3(eye, xcomp, ycomp);//eye surely wrong caus e= 0.3678. 0.1681, 0.9145

			normalize_vector(ray->vector);
			free(color);
			color = trace(ray, scene, 0);
			if (i == 2958)
			{
				printf("vpRight :");
				print_vector(vpRight);
				printf("vpUP");
				print_vector(vpUP);
				printf("pixelHeight =  %f\n", env->pixelheight);
				printf("pixelwidth %f\n", env->pixelwidth);
				printf("halfwidth %f\n", env->halfwidth);
				printf("halfheight %f\n", env->halfheight);
				printf("eye :");
				print_vector(eye);
				printf("xcomp : ");
				print_vector(xcomp);
				printf("ycomp : ");
				print_vector(ycomp);		
				printf("rayvector : ");
				print_vector(ray->vector);
				printf("ray->pos:");
				print_vector(ray->orig);
				printf("-------");
			//	return (0);
			}
		//	printf("put x = %i && color= (%f, %f, %f) && color = %f\n", pixel_x, color->x, color->y, color->z, join_color(color));
			mlx_pixel_put(mlx, win, pixel_x, pixel_y, join_color(color));
			pixel_y++;
			i++;
		}
	//	printf("y = %i\n", pixel_y);
		pixel_x++;
	}
	sleep(10);
	return (0);
}
