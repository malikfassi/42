/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:58:17 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/18 21:56:22 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <intlist.h>

t_intlist		*new_intlist(int val)
{
	t_intlist	*new;

	if ((new = (t_intlist *)malloc(sizeof(t_intlist))))
	{
		new->val = val;
		new->next = NULL;
	}
	return (new);
}

void			push_back(t_intlist **lst, t_intlist **new)
{
	t_intlist	*tmp;

	if (*lst == NULL)
	{
		*lst = *new;
		(*new)->next = NULL;
	}
	else
	{
		tmp = *lst;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = *new;
		*new = NULL;
	}
}

void			push_front(t_intlist **lst, t_intlist **new)
{
	if (*lst == NULL)
	{
		*lst = *new;
		(*lst)->next = NULL;
	}
	else
	{
		(*new)->next = *lst;
		*lst = *new;
	}
}

t_intlist		*pop_first(t_intlist **lst)
{
	t_intlist	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	return (tmp);
}

void			swap(t_intlist **lst)
{
	t_intlist	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}
