/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_fwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:32:22 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:32:26 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter_fwd(t_dlist *dlst, void (*f)(t_dlist *elem))
{
	t_dlist	*tmp;

	tmp = dlst;
	while (tmp != NULL)
	{
		(*f)(tmp);
		tmp = tmp->next;
	}
}
