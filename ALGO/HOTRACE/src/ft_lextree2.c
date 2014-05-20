/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lextree2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 19:55:49 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:10:49 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>
#include <tools.h>

void	ft_rotate_lex_tree_l(t_lextree *tree)
{
	t_lextree	*right;

	if (!tree)
	{
		right = tree->right;
		if (tree->parent)
		{
			if (tree->parent->right == tree)
				tree->parent->right = right;
			else
				tree->parent->left = right;
		}
		right->parent = tree->parent;
		if (right->left)
			right->left->parent = tree;
		tree->right = right->left;
		tree->parent = right;
		right->left = tree;
	}
}

void	ft_balances_lex_tree(t_lextree *root)
{
	if (ft_lextree_getlevel(root) == 2)
	{
		if (ft_lextree_getlevel(root->right) == -1)
			ft_rotate_lex_tree_r(root->right);
		ft_rotate_lex_tree_l(root);
	}
	else if (ft_lextree_getlevel(root) == -2)
	{
		if (ft_lextree_getlevel(root->left) == 1)
			ft_rotate_lex_tree_l(root->left);
		ft_rotate_lex_tree_r(root);
	}
	ft_balances_lex_tree(root->parent);
}

void	ft_insert_lex_tree(t_lextree *root, t_lextree *elem)
{
	int	cmp;

	cmp = ft_strcmp(elem->key, root->key);
	if (cmp < 0)
	{
		if (!root->left)
		{
			ft_add_left_lextree(root, elem);
		}
		else
			ft_insert_lex_tree(root->left, elem);
	}
	else if (cmp > 0)
	{
		if (!root->right)
		{
			ft_add_right_lextree(root, elem);
		}
		else
			ft_insert_lex_tree(root->right, elem);
	}
}

t_lextree	*ft_search_lextree(t_lextree *root, char *data)
{
	int	cmp;

	if (!root || !data)
		return (NULL);
	cmp = ft_strcmp(root->key, data);
	if (cmp == 0)
		return (root);
	if (cmp < 0)
		return (ft_search_lextree(root->right, data));
	return (ft_search_lextree(root->left, data));
}
