/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:22:48 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:44:13 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstadd_after(t_clist **aclst, t_clist *new)
{
	if (*aclst == NULL)
	{
		*aclst = new;
		return ;
	}
	if ((*aclst)->prev == NULL && (*aclst)->next == NULL)
	{
		new->prev = *aclst;
		new->next = *aclst;
	}
	else
	{
		new->prev = *aclst;
		new->next = (*aclst)->next;
	}
	new->prev->next = new;
	new->next->prev = new;
	*aclst = new;
}
