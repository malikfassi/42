/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizetree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 03:02:32 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/15 21:21:14 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>
#include <stdlib.h>
#include <tools.h>

t_sizetree	*ft_new_size_tree(int data)
{
	t_sizetree	*tree;

	tree = (t_sizetree*)malloc(sizeof(t_sizetree));
	tree->data = data;
	tree->height = 0;
	tree->balance = 0;
	tree->parent = NULL;
	tree->right = NULL;
	tree->left = NULL;
	tree->lexlist = ft_lexlist_new();
	return (tree);
}

int	ft_sizetree_getlevel(t_sizetree *root)
{
	int	deepr;
	int	deepl;
	int	result;

	if (!root || (!root->left && !root->right))
			return (0);
	deepl = ft_sizetree_getlevel(root->left);
	deepr = ft_sizetree_getlevel(root->right);
	result = 1 + ft_max(deepl, deepr);
	return (result);
}

void	ft_rotate_size_treer(t_sizetree *tree)
{
	t_sizetree	*tmp;
	t_sizetree	*top;

	tmp = tree->left;
	top = tree->parent;
	if (top)
	{
		if (tree == top->left)
			top->left = tmp;
		else
			top->right = tmp;
	}
	tmp->parent = top;
	tree->parent = tmp;
	tree->left = tmp->right;
	tmp->right = tree;
	tree->height = ft_sizetree_getlevel(tree);
	tmp->height = ft_sizetree_getlevel(tmp);
}

void	ft_add_left_sizetree(t_sizetree *tree, t_sizetree *elem)
{
	elem->parent = tree;
	tree->left = elem;
}

void	ft_add_right_sizetree(t_sizetree *tree, t_sizetree *elem)
{
	elem->parent = tree;
	tree->right = elem;
}
void	ft_rotate_size_treel(t_sizetree *tree)
{
	t_sizetree	*tmp;
	t_sizetree	*top;

	tmp = tree->right;
	top = tree->parent;
	if (top)
	{
		if (tree == top->left)
			top->left = tmp;
		else
			top->right = tmp;
	}
	tmp->parent = top;
	tree->parent = tmp;
	tree->right = tmp->left;
	tmp->left = tree;
	tree->height = ft_sizetree_getlevel(tree);
	tmp->height = ft_sizetree_getlevel(tmp);
}

t_sizetree	*ft_insert_size_tree(t_sizetree *root, int data)
{
	if (data < root->data)
	{
		if (!root->left)
		{
			ft_add_left_sizetree(root, ft_new_size_tree(data));
			root->left->height = 1;
			return (root->left);
		}
		else
			root = ft_insert_size_tree(root->left, data);
	}
	else if (data > root->data)
	{
		if (!root->right)
		{
			ft_add_right_sizetree(root, ft_new_size_tree(data));
			root->right->height = 1;
			return (root->right);
		}
		else
			root = ft_insert_size_tree(root->right, data);
	}
	return (root);
}

void	ft_balances_size_tree(t_sizetree *tree)
{
	int			balance;
	t_sizetree	*tmp_tree;
	t_sizetree	*tmp_parent;

	balance = 0;
	tmp_parent = tree;
	while (tmp_parent->parent && balance != 2 && balance != -2)
	{
		tmp_tree = tmp_parent;
		tmp_parent = tmp_tree->parent;
		tmp_parent->height = ft_sizetree_getlevel(tmp_parent);
		balance = ft_sizetree_getlevel(tmp_parent->right);
		balance -= ft_sizetree_getlevel(tmp_parent->left);
	}
	if (balance == 2 || balance == -2)
		ft_balances_size_tree_root(tmp_parent, tmp_tree);
}

void	ft_balances_size_tree_root(t_sizetree *root, t_sizetree *top)
{
	if (top == root->left && root->balance == -2)
	{
		if (top->balance < 1)
			ft_rotate_size_treer(root);
		else
		{
			ft_rotate_size_treel(top);
			ft_rotate_size_treer(root);
		}
	}
	else if (top != root->left)
	{
		if (root->balance == 2)
		{
			if (top->balance > -1)
				ft_rotate_size_treel(root);
			else
			{
				ft_rotate_size_treer(top);
				ft_rotate_size_treel(root);
			}
		}
	}
}

t_sizetree	*ft_search_sizetree(t_sizetree *root, int data)
{
	if (!root)
	{
		return (NULL);
	}
	if (root->data == data)
	{
		return (root);
	}
	if (root->data < data)
	{
		return (ft_search_sizetree(root->right, data));
	}
	return (ft_search_sizetree(root->left, data));
}

