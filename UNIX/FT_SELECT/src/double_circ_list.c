/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_circ_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:34:54 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/12 19:43:28 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

typedef struct	s_dc_list
{
	char				*val;
	struct s_dc_list	*next;
	struct s_dc_list	*prev;
}				t_dc_list;

t_dc_list	*new_dc_list(char *val)
{
	t_dc_list	*new;

	if (!(new = (t_dc_list *)malloc(sizeof(t_dc_list))))
		return (NULL);
	new->val = val;
	new->prev = new;
	new->next = new;
	return (new);
}

void		add_dc_list(t_dc_list **list, t_dc_list *new)
{
	if (!*list)
		*list = new;
	else
	{
		(*list)->prev->next = new;
		new->prev = (*list)->prev;
		new->next = *list;
		(*list)->prev = new;
		*list = new;
	}
}

void		rm_list(t_dc_list **list)
{
	t_dc_list	*prev;
	t_dc_list	*next;

	if ((*list)->next == *list)
	{
		*list = NULL;
		return ;
	}
	prev = (*list)->prev;
	next = (*list)->next;
	prev->next = next;
	next->prev = prev;
	(*list) = next;
}

t_dc_list	*fill_list(int argc, char **argv)
{
	int			i;
	t_dc_list	*list;
	t_dc_list	*new;

	i = 2;
	list = NULL;
	while (argc > 1)
	{
		new = new_dc_list(argv[argc - 1]);
		add_dc_list(&list, new);
		argc--;
	}
	return (list);
}
