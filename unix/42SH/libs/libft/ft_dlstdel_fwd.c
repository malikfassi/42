/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_fwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:28:52 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:28:53 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlstdel_fwd(t_dlist **adlst, void (*del)(void *, size_t))
{
	t_dlist	*dlst;
	t_dlist	*tmp;

	dlst = (*adlst)->next;
	while (dlst != NULL)
	{
		tmp = dlst;
		dlst = tmp->next;
		(*del)(tmp->content, tmp->content_size);
		free((t_dlist *)tmp);
	}
}
