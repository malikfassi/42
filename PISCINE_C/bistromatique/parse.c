/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/05 13:24:16 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 16:22:19 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

void	parse_nb(char *str, long long *i, char **av, t_list **l)
{
	char	*tmp;

	if (c_in_s(str[*i], av[1]))
	{
		while (str[*i] && str[*i] == av[1][0])
		{
			(*i)++;
		}
		if (str[*i] && c_in_s(str[*i], av[1]))
		{
			tmp = p_val(str, i, av);
		}
		else
		{
			(*i)--;
			tmp = p_str(1, str, i);
		}
		add_list(l, tmp);
	}
}

void	parse_sign(char *str, long long *i, char **av, t_list **l)
{
	char	c;

	c = addmin(str, i, av[2]);
	if (c == av[2][3] && str[*i] == av[2][0])
	{
		p_add_list(3, av[2][3], av[2][0], l);
		(*i)++;
		i[1]++;
		return ;
	}
	if (c == av[2][3] && c_in_s(str[*i], av[1]))
	{
		while (str[*i] && str[*i] == av[1][0])
		{
			(*i)++;
		}
		if (str[*i] && c_in_s(str[*i], av[1])) 
		{
			str[--(*i)] = c;
			add_list(l, p_val(str, i, av));
		}
		else
		{
			p_add_list(2, av[1][0], 42, l);
		}
	}
}

void	parse_am(char *str, long long *i, char **av, t_list **l)
{
	char	*last;

	if (str[*i] && is_am(str[*i], av[2]))
	{
		last = (*l) ? (list_last(*l))->data : NULL;
		if (!(*l) || (is_op(last[0], av[2]) && !(c_in_s(last[1], av[1]))))
		{
			parse_sign(str, i, av, l);
		}
		else
		{
			add_list(l, p_str(1, str, i));
		}
	}
}

t_list	*check_parent(t_list *l, long long *i)
{
	if (i[1] != i[2])
	{
		return (NULL);
	}
	return (l);
}

t_list	*parse(char **av, char *str)
{
	t_list		*l;
	long long	i[3];

	l = NULL;
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (str[i[0]])
	{
		if (!(c_in_s(str[i[0]], av[1])) && !(c_in_s(str[i[0]], av[2])))
		{
			return (NULL);
		}
		parse_nb(str, &i[0], av, &l);
		parse_am(str, &i[0], av, &l);
		if (str[i[0]] && is_pm(str[i[0]], av[2]))
		{
			i[1] = (str[i[0]] == av[2][0]) ? i[1] + 1 : i[1];
			i[2] = (str[i[0]] == av[2][1]) ? i[2] + 1 : i[2];
			add_list(&l, p_str(1, str, &i[0]));
		}
	}
	return (check_parent(l,i));
}
