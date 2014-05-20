/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:27:00 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:27:01 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_before(t_dlist **adlst, t_dlist *new)
{
	if (*adlst != NULL)
	{
		new->next = *adlst;
		new->next->prev = new;
		new->prev = (*adlst)->prev;
		if (new->prev != NULL)
			new->prev->next = new;
	}
	*adlst = new;
}
