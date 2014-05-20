/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 13:23:36 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/02 12:21:04 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (!content)
	{
		content = NULL;
		content_size = 0;
	}
	lst->content = (void *)content;
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
