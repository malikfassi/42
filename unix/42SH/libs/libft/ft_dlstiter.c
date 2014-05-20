/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:32:04 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:32:05 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter(t_dlist *dlst, void (*f)(t_dlist *elem))
{
	t_dlist	*tmp;

	tmp = dlst->prev;
	ft_dlstiter_fwd(dlst, (*f));
	ft_dlstiter_rwd(tmp, (*f));
}
