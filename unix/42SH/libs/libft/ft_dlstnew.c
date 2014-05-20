/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:34:04 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:34:05 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
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
