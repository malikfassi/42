/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:21:31 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/19 14:39:49 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <mlx.h>
typedef struct	s_2Dvector
{
	double	x;
	double	y;
}				t_2Dvector;


typedef struct	s_3Dvector
{
	double x;
	double y;
	double z;
}				t_3Dvector;

void	fdf(int fd, void *mlx, void *win);
void	display(char **splitted_line1, char **splitted_line2, void *mlx, void *win, double j);
#endif
