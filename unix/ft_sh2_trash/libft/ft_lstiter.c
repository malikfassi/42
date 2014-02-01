/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:45:11 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/27 18:31:20 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list* elem))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
}
