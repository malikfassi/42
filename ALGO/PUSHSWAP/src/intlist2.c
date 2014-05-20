/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:55:55 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/18 21:57:41 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intlist.h>
#include <libft.h>

void		pop_n_push(t_intlist **l_a, t_intlist **l_b)
{
	t_intlist	*tmp;

	tmp = pop_first(l_b);
	push_front(l_a, &tmp);
}

t_intlist	*fill_l_a(int argc, char **argv)
{
	int			i;
	t_intlist	*l_a;
	t_intlist	*new;

	i = 2;
	l_a = new_intlist(ft_atoi(argv[1]));
	while (i < argc)
	{
		new = new_intlist(ft_atoi(argv[i]));
		push_back(&l_a, &new);
		i++;
	}
	return (l_a);
}

int			is_sorted(t_intlist *lst)
{
	while (lst && lst->next)
	{
		if (lst->val > lst->next->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void		sort_la(t_intlist **l_a, t_intlist **l_b)
{
	while ((*l_a)->next)
	{
		if ((*l_a)->val < (*l_a)->next->val)
		{
			pop_n_push(l_b, l_a);
			ft_putstr("pb ");
		}
		else
		{
			swap(l_a);
			ft_putstr("sa ");
		}
	}
}

void		sort_lb(t_intlist **l_b, t_intlist **l_a)
{
	while (*l_b)
	{
		if (!(*l_b)->next || (*l_b)->val > (*l_b)->next->val)
		{
			pop_n_push(l_a, l_b);
			if (!(*l_b) && is_sorted((*l_a)))
				ft_putstr("pa\n");
			else
				ft_putstr("pa ");
		}
		else
		{
			swap(l_b);
			ft_putstr("sb ");
		}
	}
}
