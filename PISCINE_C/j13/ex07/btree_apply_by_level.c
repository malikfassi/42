/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 20:15:31 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/02 21:22:32 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>
int	get_node_number(t_btree *root, int nb)
{
	if (root->left)
	{
		nb = get_node_number(root->left, ++nb);
	}
	if (root->right)
	{
		nb = get_node_number(root->right, ++nb);
	}
	return(nb);
}


int ft_power(int nb, int power)
{
	if (power >= 1)
		return (nb * ft_power(nb, power - 1));
	else if (power == 0)
		if (nb < 0)
			return (-1);
		else
			return (1);
	else
		return (0);
}
int max(int a, int b)
{
	if (a > b)
	{
		return(a);
	}
	return(b);
}


int btree_level_count(t_btree *root)
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
	{
		return (0);
	}
	return (max(btree_level_count(root->left), btree_level_count(root->right)) + 1);
}


void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, 
			int current_level, int is_first_elem))
{
	t_btree **levels;

	if(root)
	{
		int level;
		int node_per_lvl;
		int tot_lvl;
		t_btree *current_node;
		t_btree **current_lvl;
		t_btree **last-lvl;
		
		tot_lvl = btree_level_count(t_btree *root) + 1;

		level = 0;
		while (tot_lvl)
		{
			node_per_lvl = ft_power(2, level);
			current_lvl = malloc(sizeof(t_btree) * node_per_level);
			current_lvl[0] = root;
			while (
					}
					}
					}


