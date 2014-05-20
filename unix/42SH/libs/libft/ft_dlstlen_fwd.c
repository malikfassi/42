/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlen_fwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:33:23 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:33:24 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlstlen_fwd(t_dlist *dlst)
{
	size_t	n;
	t_dlist	*tmp;

	if (!dlst)
		return (0);
	n = 0;
	tmp = dlst;
	while (tmp != NULL)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}
