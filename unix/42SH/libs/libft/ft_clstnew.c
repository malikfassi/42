/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:25:51 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:25:52 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_clist	*ft_clstnew(void const *content, size_t content_size)
{
	t_clist	*new;

	new = (t_clist *)malloc(sizeof(t_clist));
	if (new == NULL)
		return (NULL);
	if (!content)
	{
		content = NULL;
		content_size = 0;
	}
	new->content = (void *)content;
	new->content_size = content_size;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
