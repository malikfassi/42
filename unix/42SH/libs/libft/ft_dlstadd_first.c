/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:27:54 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:27:55 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_first(t_dlist **adlst, t_dlist *new)
{
	t_dlist	*tmp;

	if (*adlst != NULL)
	{
		tmp = *adlst;
		while (tmp->prev != NULL)
			tmp = tmp->prev;
		new->next = tmp;
		tmp->prev = new;
	}
	*adlst = new;
}
