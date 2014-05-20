/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:57:29 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/18 21:59:31 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTLIST_H
# define INTLIST_H

typedef struct		s_intlist
{
	int					val;
	struct s_intlist	*next;
	struct s_intlist	*previous;
}					t_intlist;

t_intlist			*new_intlist(int val);
void				push_front(t_intlist **lst, t_intlist **new);
void				push_back(t_intlist **lst, t_intlist **new);
t_intlist			*pop_first(t_intlist	**lst);
void				swap(t_intlist	**lst);
#endif
