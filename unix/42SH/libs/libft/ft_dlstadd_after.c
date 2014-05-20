/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:26:35 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:26:36 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_after(t_dlist **adlst, t_dlist *new)
{
	if (*adlst != NULL)
	{
		new->prev = *adlst;
		new->prev->next = new;
		new->next = (*adlst)->next;
		if (new->next != NULL)
			new->next->prev = new;
	}
	*adlst = new;
}
