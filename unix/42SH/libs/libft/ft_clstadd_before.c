/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:23:13 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:44:40 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstadd_before(t_clist **aclst, t_clist *new)
{
	if (*aclst == NULL)
	{
		*aclst = new;
		return ;
	}
	if ((*aclst)->prev == NULL && (*aclst)->next == NULL)
	{
		new->next = *aclst;
		new->prev = *aclst;
	}
	else
	{
		new->next = *aclst;
		new->prev = (*aclst)->prev;
	}
	new->next->prev = new;
	new->prev->next = new;
	*aclst = new;
}
