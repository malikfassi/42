/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lextree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 06:33:39 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/15 21:17:08 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>
#include <tools.h>

t_lextree	*ft_new_lextree(char *key, char *value)
{
	t_lextree	*tree;

	tree = (t_lextree *)malloc(sizeof(t_lextree));
	tree->key = ft_strdup(key);
	tree->value = ft_strdup(value);
	tree->height = 0;
	tree->balance = 0;
	tree->parent = NULL;
	tree->right = NULL;
	tree->left = NULL;
	tree->subtree_data = NULL;
	return (tree);
}

int	ft_lextree_getlevel(t_lextree *root)
{
	int	deepl;
	int	deepr;
	int	result;

	deepl = 0;
	deepr = 0;
	if (root->left)
		deepl += ft_lextree_getlevel(root->left);
	if (root->right)
		deepr += ft_lextree_getlevel(root->right);
	result = (deepl > deepr) ? deepl : deepr;
	return (1 + result);
}

void	ft_rotate_lex_tree_r(t_lextree *tree)
{
	t_lextree	*left;

	if (tree)
	{
		left = tree->left;
		if (tree->parent)
		{
			if (tree->parent->left == tree)
				tree->parent->left = left;
			else
				tree->parent->right = left;
		}
		left->parent = tree->parent;
		if (left->right)
			left->right->parent = tree;
		tree->left = left->left;
		tree->parent = left;
		left->right = tree;
	}
}

void	ft_add_left_lextree(t_lextree *tree, t_lextree *elem)
{
	elem->parent = tree;
	tree->left = elem;
}

void	ft_add_right_lextree(t_lextree *tree, t_lextree *elem)
{
	elem->parent = tree;
	tree->right = elem;
}

