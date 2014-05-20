/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 03:43:54 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:30:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>
#include <ft_data.h>
#include <tools.h>
#include <get_next_line.h>
#include <fcntl.h>

t_sizetree	*ft_init_data(void)
{
	char	*line;
	char	*key;
	char	*value;
	t_sizetree	*root;

	root = ft_new_size_tree(0);
	while (get_next_line(0, &line) && ft_strlen(line))
	{
		if (ft_strlen(line) > 0)
		{
			key = ft_strdup(line);
			get_next_line(0, &line);
			value = ft_strdup(line);
			ft_add_data(root, key, value);
		}
	}
	return (root);
}

void	ft_search_data(t_sizetree *root)
{
	char	*key;
	char	*value;

	while (get_next_line(0, &key) && ft_strlen(key))
	{
		value = ft_get_data(key, root);
		if (value)
			ft_putstr(value);
		else
		{
			ft_putstr(key);
			ft_putstr(": ");
			ft_putstr("Not Found");
		}
		ft_putstr("\n");
	}
}

void	ft_add_data(t_sizetree *root, char *key, char *value)
{
	t_sizetree	*new;
	t_lextree	*newlex;
	t_sizetree	*nodesize;
	t_lexlist	*lexlist;

	new = ft_new_size_tree(ft_strlen(key));
	newlex = ft_new_lextree(key, value);
	nodesize = ft_insert_size_tree(root, ft_strlen(key));
	lexlist = ft_getlastlex(nodesize->lexlist);

	if (!lexlist->lextree)
	{
		lexlist->lextree = newlex;
	}
	else if (ft_lextree_getlevel(lexlist->lextree) >= MAX_LEX_HEIGHT)
	{
		lexlist->next = ft_lexlist_new();
		lexlist->next->lextree = newlex;
	}
	else
	{
		ft_insert_lex_tree(lexlist->lextree, newlex);
	}
}

char	*ft_get_data(char *key, t_sizetree *root)
{
	char	*value;
	t_sizetree	*nodesize;
	t_lextree	*rootlex;
	t_lextree	*nodelex;
	t_lexlist	*lexlist;

	value = NULL;
	nodesize = ft_search_sizetree(root, ft_strlen(key));
	lexlist = nodesize->lexlist;
	if (nodesize)
	{
		while (!value && lexlist)
		{
			rootlex = lexlist->lextree;
			if (rootlex)
			{
				nodelex = ft_search_lextree(rootlex, key);
				if (nodelex)
					value = nodelex->value;
			}
			lexlist = lexlist->next;
		}
	}
	return (value);
}

