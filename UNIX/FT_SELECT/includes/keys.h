/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 21:02:54 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:09:22 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

void	go_up(t_dc_list **list, int *is_selected, int *line, int argc);
void	go_down(t_dc_list **list, int *is_selected, int *line, int argc);
int		*ft_delete(int *line, int *nb, t_dc_list **list, int *is_selected);
void	ft_space(int *line, int *is_selected, t_dc_list **list, int nb);
int		*ft_return(int *line, t_dc_list **list, int *is_selected);

#endif
