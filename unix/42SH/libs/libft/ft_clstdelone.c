/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:24:10 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:45:10 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_clstdelone(t_clist **aclst, void (*del)(void *, size_t))
{
	t_clist	*tmp;

	tmp = *aclst;
	if (tmp->prev != NULL)
	{
		tmp->prev->next = tmp->next;
		*aclst = tmp->prev;
	}
	if (tmp->next != NULL)
	{
		tmp->next->prev = tmp->prev;
		*aclst = tmp->next;
	}
	(*del)(tmp->content, tmp->content_size);
	if (tmp->next == NULL && tmp->prev == NULL)
		*aclst = NULL;
	free((t_clist *)tmp);
}
