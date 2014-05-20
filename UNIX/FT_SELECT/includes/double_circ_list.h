/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_circ_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:55:59 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:32:39 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_CIRC_LIST_H
# define DOUBLE_CIRC_LIST_H

typedef struct	s_dc_list
{
	char				*val;
	struct s_dc_list	*next;
	struct s_dc_list	*prev;
}				t_dc_list;

t_dc_list	*new_dc_list(char *val);
void		add_dc_list(t_dc_list **list, t_dc_list *new);
t_dc_list	*fill_list(int argc, char **argv);
void		rm_list(t_dc_list **list);
#endif
