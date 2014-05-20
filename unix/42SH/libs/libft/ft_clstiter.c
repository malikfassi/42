/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:25:05 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:45:53 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstiter(t_clist *clst, void (*f)(t_clist *elem))
{
	t_clist	*tmp;

	if (!clst)
		return ;
	tmp = clst;
	while (tmp != clst->prev)
	{
		(*f)(tmp);
		tmp = tmp->next;
	}
	(*f)(tmp);
}
