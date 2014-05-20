/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 21:01:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:18:52 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <double_circ_list.h>

void	rewrite(t_dc_list *list, int *is_selected, int line, int fd);
void	new_line(t_dc_list *list, int *is_selected, int line, int fd);
void	display(t_dc_list *lst, int *is_selected, int fd);

#endif
