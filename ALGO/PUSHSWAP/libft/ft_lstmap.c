/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 20:11:54 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/04/19 08:44:43 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	get_lst_len(t_list *lst)
{
	t_list	*tmp;
	size_t	len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*prev;
	t_list	*first;

	first = NULL;
	prev = NULL;
	while (lst != NULL)
	{
		new = (*f)(lst);
		if (new == NULL)
			return (NULL);
		if (!first)
		{
			first = new;
			first->next = NULL;
		}
		else if (first && first->next == NULL)
			first->next = new;
		if (prev)
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (first);
}
