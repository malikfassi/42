/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/31 21:21:10 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/31 23:20:05 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_create_elem(data);
	tmp = *begin_list;
	*begin_list = new;
	new->next = *begin_list;
}
