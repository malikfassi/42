/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 21:05:39 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:06:29 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

void	ft_select(int *is_selected, t_dc_list *list, int line);
void	ft_unselect(t_dc_list *list, int line, int *is_selected);

#endif
