/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:23:41 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:23:42 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_clstdel(t_clist **aclst, void (*del)(void *, size_t))
{
	t_clist	*tmp;

	(*aclst)->prev->next = NULL;
	(*aclst)->prev = NULL;
	while (*aclst != NULL)
	{
		tmp = *aclst;
		(*del)(tmp->content, tmp->content_size);
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		*aclst = tmp->next;
		free((t_clist *)tmp);
	}
	*aclst = NULL;
}
