/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:08:10 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/19 13:53:36 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <fdf.h>
#include <stdlib.h>
t_2Dvector	*new_2Dvector(double x, double y);
t_3Dvector	*new_3Dvector(double x, double y, double z);
t_2Dvector	*vector3D_to_2D(t_3Dvector	*vector);

#endif
