/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxOp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:10:59 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/19 14:47:43 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXOP_H
# define MLXOP_H

#include <fdf.h>
#define OFFSETX 100
#define OFFSETY 100
void	draw_horizontal_lines(t_2Dvector *start, double nb, void *mlx, void *win);
void	draw_vertical_lines(t_2Dvector *start, t_2Dvector *dim, void *mlx, void *win);
void	ft_draw_line(void *mlx, void *win, t_2Dvector *point_a, t_2Dvector *point_b);
#endif
