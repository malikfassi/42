/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:03:31 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/02 12:20:13 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (*alst != NULL)
	{
		tmp = *alst;
		(*del)(tmp->content, tmp->content_size);
		*alst = tmp->next;
		free((void *)tmp);
	}
	*alst = NULL;
}
