/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_rwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:32:40 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:32:41 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter_rwd(t_dlist *dlst, void (*f)(t_dlist *elem))
{
	t_dlist	*tmp;

	tmp = dlst;
	while (tmp != NULL)
	{
		(*f)(tmp);
		tmp = tmp->next;
	}
}
