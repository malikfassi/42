/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/09 04:55:39 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 16:09:04 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

void	add_pmop(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	(*lst)->data[0] = '(';
	(*lst)->data[1] = '\0';
	tmp1 = create_elem("-1");
	tmp2 = create_elem("*");
	tmp3 = create_elem("(");
	tmp1->next = tmp2;
	tmp2->next = tmp3;
	tmp3->next = (*lst)->next;
	(*lst)->next = tmp1;
	(*lst) = tmp3;
}

void	add_cp(t_list *lst, long long *p, char *av2)
{
	t_list	*tmp1;
	t_list	*tmp2;
	char	*d;

	d = lst->data;
	p[0] = (d[0] == av2[0] || d[1] == av2[0]) ? p[0] + 1 : p[0];
	p[1] = (d[0] == av2[1]) ? p[1] + 1 : p[1];
	if (p[0] > 0 && p[0] == p[1])
	{		
		tmp1 = create_elem(")");
		tmp2 = lst->next;
		lst->next = tmp1;
		tmp1->next = tmp2;
	}
}

void	parse_parent(t_list *lst, char *av2)
{
	t_list		*tmp;
	t_list		*tmp2;
	long long	p[2]; 

	tmp2 = lst;
	while (tmp2)
	{
		while (tmp2 && (tmp2->data[0] != av2[3] || tmp2->data[1] != av2[0]))
		{
			tmp2 = tmp2->next;
		}
		if (tmp2)
		{
			add_pmop(&tmp2);
			tmp = tmp2;
			p[0] = 0;
			p[1] = 0;
			while (tmp)
			{
				add_cp(tmp, p, av2);
				tmp = (p[0] > 0 && p[0] == p[1]) ? NULL : tmp->next;
			}
			tmp2 = tmp2->next;
		}
	}
}

int		is_mdm(char c, char *av2)
{
	if (c == av2[4] || c == av2[5] || c == av2[6])
	{
		return (1);
	}
	return (0);
}
