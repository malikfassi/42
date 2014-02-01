/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:02:35 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/02 21:07:47 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <stdio.h>
t_2Dvector	*new_2Dvector(double x, double y)
{
	t_2Dvector *vector;
	
	if(!(vector = (t_2Dvector *)malloc(sizeof(t_2Dvector))))
			return (NULL);
	vector->x = x;
	vector->y = y;
	return (vector);
}

t_3Dvector	*new_3Dvector(double x, double y, double z)
{
	t_3Dvector	*vector;

	if(!(vector = (t_3Dvector *)malloc(sizeof(t_3Dvector))))
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_2Dvector	*vector3D_to_2D(t_3Dvector *vector)
{
	double x;
	double y;
	double deux;
	double trois;
	double un;

	un = 1;
	deux = 2;
	trois = 3;
	x = ((deux / trois) * vector->x) - ((un / trois) * vector->y) - ((un / trois) * vector->z);
	y = (-un/trois) * vector->x + (deux / trois) * vector->y - (un / trois) * vector->z;
	printf("X= %f, Y=%f\n", x, y);
	printf("vX= %f, vY=%f\n", vector->x, vector->y);
	return (new_2Dvector(x, y));
}
