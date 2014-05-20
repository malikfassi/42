/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 21:00:06 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:16:29 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GO_H
# define GO_H

# include <double_circ_list.h>

void	go_to_up(int *line);
void	go_to_down(int argc, int *line);
void	del_go_up(t_dc_list **list, int *is_selected, int *line, int nb);

#endif
