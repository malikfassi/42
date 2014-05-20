/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:30:44 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:26:27 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))))
	{
		if (content)
		{
			if ((new->content = (void *)malloc(content_size)))
			{
				ft_memcpy(new->content, content, content_size);
				ft_memcpy(&new->content_size, &content_size, \
							sizeof(content_size));
			}
			else
				return (NULL);
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
	}
	else
		return (NULL);
	return (new);
}
