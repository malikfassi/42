/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:25:30 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:25:31 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_clstlen(t_clist *clst)
{
	size_t	n;
	t_clist	*tmp;

	if (!clst)
		return (0);
	n = 1;
	tmp = clst->next;
	while (tmp != NULL && tmp != clst)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}
