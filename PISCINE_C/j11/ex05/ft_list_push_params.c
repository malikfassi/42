/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/31 22:25:30 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/31 23:41:15 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
t_list	*ft_list_push_params(int ac, char **av)
{
	int	count;
	t_list *new;
	t_list *cpy;
	
	count = 0;
	cpy = new;
	if (ac > 1)
	{
		new = ft_create_elem(av[count]);
		count++;
		cpy = new;
		while (count < ac)
		{
			cpy = cpy->next;
			cpy = ft_create_elem(av[count]);
			count++;
		}
	}
	return (new);
}
