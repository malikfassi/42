/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:00:36 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/18 21:59:42 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTLIST2_H
# define INTLIST2_H

void		pop_n_push(t_intlist **l_a, t_intlist **l_b);
t_intlist	*fill_l_a(int argc, char **argv);
int			is_sorted(t_intlist *lst);
void		sort_la(t_intlist **l_a, t_intlist **l_b);
void		sort_lb(t_intlist **l_b, t_intlist **l_a);

#endif
