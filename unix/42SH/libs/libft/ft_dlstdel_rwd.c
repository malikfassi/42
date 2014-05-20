/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_rwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:29:07 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:29:08 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlstdel_rwd(t_dlist **adlst, void (*del)(void *, size_t))
{
	t_dlist	*dlst;
	t_dlist	*tmp;

	dlst = (*adlst)->prev;
	while (dlst != NULL)
	{
		tmp = dlst;
		dlst = tmp->prev;
		(*del)(tmp->content, tmp->content_size);
		free((t_dlist *)tmp);
	}
}
