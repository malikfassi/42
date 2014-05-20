/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 18:57:57 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/13 04:02:44 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list *alst, t_list *new)
{
	t_list	*tmp;

	tmp = alst;
	new->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
