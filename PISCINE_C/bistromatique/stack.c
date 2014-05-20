/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/03 16:36:20 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 11:36:36 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

t_stack	*create_stack(char *c)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (elem)
	{
		elem->c = c;
		elem->next = NULL;
	}
	return (elem);
}

t_stack	*push(t_stack *top, char *c)
{
	t_stack	*elem;

	elem = NULL;
	elem = create_stack(c);
	if (elem && top)
	{
		elem->next = top;
	}
	return (elem);
}

char	*pull(t_stack **top)
{
	t_stack	*elem;
	char	*ret;
	
	ret = NULL;
	if (*top)
	{
		elem = *top;
		ret = elem->c;
		*top = elem->next;
		elem->c = NULL;
		elem->next = NULL;
		free(elem);
	}
	return (ret);
}

void	free_stack(t_stack **top)
{
	while (*top)
	{
		pull(top);
	}
	*top = NULL;
}
