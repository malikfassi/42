/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/05 15:49:05 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/07 05:37:44 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

t_list	*create_elem(char *data)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void	add_list(t_list **begin_list, char *data)
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
		{
			list = list->next;
		}
		list->next = create_elem(data);
	}
	else
	{
		list = create_elem(data);
		*begin_list = list;
	}
}

t_list	*list_last(t_list *begin_list)
{
	while (begin_list->next)
	{
		begin_list = begin_list->next;
	}
	return (begin_list);
}
