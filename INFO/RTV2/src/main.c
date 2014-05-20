/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 13:58:39 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/02/14 18:42:19 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

#include <stdio.h>
int	sphere_intersection(t_sphere *sphere, t_ray *ray, double *coef)
{
	t_V3D_double	*dist;
	double			*tab;
	int				ret;

	tab = (double *)malloc(sizeof(float) * 4);
	ret = 0;
	dist = vect_copy(sphere->pos);
	tab[0]= vect_mult(ray->dir, dist);
	tab[1] = pow(tab[0], 2) - vect_mult(dist, dist) + pow(sphere->radius, 2);
	printf("avant tab[1] = %f\n", tab[1]);
	if (tab[1] < 0)
		return (ret);
	printf("apres\n");
	tab[2] = tab[0] - sqrt(tab[1]);
	tab[3] = tab[0] + sqrt(tab[1]);
	printf("tab[2] = %f tab[3] = %f coef = %f\n", tab[2], tab[3], *coef);
	if (tab[2] > (double)0.1 && tab[2] < *coef)
	{
		*coef = tab[2];
		ret = 1;
	}
	if (tab[3] > (double)0.1 && tab[3] < *coef)
	{
		*coef = tab[3];
		ret = 1;
	}
	free(tab);
	return (ret);
}	


void	print_vector(t_V3D_double	*vect)
{
	printf("(%f, %f, %f)\n", vect->x, vect->y, vect->z);
}


int	main(void)
{
	t_cam		*cam;
	int			pixel_x;
	int			pixel_y;
	t_ray		*ray;
	t_sphere	*sphere;
	void		*mlx;
	void		*win;
	double		coef;


	pixel_y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, RES_X, RES_Y, "RTV1");
	cam = new_cam(NULL, NULL, 0);
	ray = new_ray(new_V3D_double(0, 0, -1), NULL);
	sphere = new_sphere(new_V3D_double(0, 0, 200), 40);
	while (pixel_y < RES_Y)
	{
		pixel_x = 0;
		while (pixel_x < RES_X)
		{
			cam->target->x = pixel_x - (RES_X / 2);
			cam->target->y = pixel_y - (RES_Y / 2);
			cam->target->z = -(RES_X / 2 * tan(FOV / 2));
			print_vector(cam->target);
			normalize_vector(cam->target);
			print_vector(cam->target);
			ray->dir->x = cam->target->x - ray->orig->x;
			ray->dir->y = cam->target->y - ray->orig->y;
			ray->dir->z = cam->target->z - ray->orig->z;
			normalize_vector(ray->dir);
			coef = COEF;
			if (sphere_intersection(sphere, ray, &coef) && coef < COEF)
			{
				printf("je put (%i, %i)\n", pixel_x, pixel_y);
				mlx_pixel_put(mlx, win, pixel_x, pixel_y, 0xFFFFFF);
			}
			pixel_x++;
		}
		pixel_y++;
	}
	sleep(10);
	return (0);
}
