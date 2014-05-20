/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/03 19:16:58 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 16:13:35 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

void	operators(t_list **ret, t_stack **tmp, char *c, char *av2)
{
	char	t;

	if (*tmp)
	{
		t = (*tmp)->c[0];
		while (is_ammdm(t, av2))
		{
			if (is_am(c[0], av2) || (is_mdm(c[0], av2) && is_mdm(t, av2)))
			{
				add_list(ret, pull(tmp));
				t = (*tmp) ? (*tmp)->c[0] : 0;
			}
			else
			{
				t = 0;
			}
		}
	}
	*tmp = push(*tmp, c);
}

void	rpn_inloop(t_list **ret, t_stack **tmp, char *c, char **av)
{
	if (c_in_s(c[0], av[1]) || (c[0] == av[2][3]
			&& c_in_s(c[1], av[1])))
	{
		add_list(ret, c);
	}
	else
	{
		if (is_ammdm(c[0], av[2]))
		{
			operators(ret, tmp, c, av[2]);
		}
	}
	if (c[0] == av[2][0])
	{
		*tmp = push(*tmp, c);
	}
	if (c[0] == av[2][1])
	{
		while ((*tmp)->c[0] != av[2][0])
		{
			add_list(ret, pull(tmp));
		}
		pull(tmp);
	}
}

t_list	*trans_rpn(t_list *list, char **av)
{
	t_list		*ret;
	t_stack		*tmp;
	long long	i;

	ret = NULL;
	tmp = NULL;
	i = -1;
	while (list)
	{
		rpn_inloop(&ret, &tmp, list->data, av);
		list = list ->next;
	}
	while (tmp)
	{
		add_list(&ret, pull(&tmp));
	}
	free_stack(&tmp);
	return (ret);
}

char	*calc_tot(char *a, char *b, char c, char **av)
{
	if (c == av[2][2])
	{
		return (add(a, b, av));
	}
	if (c == av[2][3])
	{
		return (sub(a, b, av));
	}
	if (c == av[2][4])
	{
		return (mult(a, b, av));
	}
	/*if (c == av[2][5])
	{
		return (a / b);
	}
	return (a % b);*/
	return (a);
}

char	*calc_rpn(t_list *rpn, char **av)
{
	char	*a;
	char	*b;
	char	*res;
	t_stack	*tmp;

	tmp = NULL;
	while (rpn)
	{
		if (c_in_s(rpn->data[0], av[1]) || (rpn->data[0] == av[2][3]
					&& c_in_s(rpn->data[1], av[1])))
		{
			tmp = push(tmp, rpn->data);
		}
		else
		{
			b = pull(&tmp);
			a = pull(&tmp);
			if (!a || !b)
			{
				return (NULL);
			}
			res = calc_tot(a, b, rpn->data[0], av);
			tmp = push(tmp, res);
		}
		rpn = rpn->next;
	}
	res = (tmp->next) ? NULL : tmp->c;
	free_stack(&tmp);
	return (res);
}
