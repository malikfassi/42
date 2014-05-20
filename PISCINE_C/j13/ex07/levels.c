/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 21:36:34 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/02 22:16:49 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

int get_node_number(t_btree *root, int nb)
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


int get_depth(t_btree *root)
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
	{
		return (0);
	}
	return (max(get_depth(root->left), get_depth(root->right)) + 1);
}


void	ft_swap(t_btree **list1, f_btree **list2)
{
	t_btree *tmp;

	*tmp = *list1;
	*list1 = *list2;
	*list2 = *tmp;
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int lvl;
	int max_depth;
	int len_current_lvl;
	t_btree	**current_lvl;
	t_btree **next_lvl
	int count;
	int count2;

	lvl = 0;
	count = 0;
	max_depth = get_depth(root);
	len_current_lvl = power(2, lvl);
	current_lvl = malloc(sizeof(t_btree) * len_current_lvl);
	current_lvl[0] = root;
	while(count < maxDepth + 1)
	{
		len_current_lvl = (2, lvl);
		next_lvl = malloc(sizeof(t_btree) * ft_power(2,lvl+1));
		count2 = 0
		while (count2 < len_current_lvl)
			{
				if(!currentEtage[count2])
				{
					next_lvl[2 * count2] = NULL;
					next_lvl[(2 * count2) + 1] = NULL;
				}
				else
				{
					next_lvl[2 * i] = next_lvl[i]->left;
					next_lvl[(2 * i) + 1] = next_lvl[i]->right;
				}
				count2++;
			}
			etage++;
			ft_swap(current_lvl,next_lvl);
			free next_lvl;
			count++;
		}
	free current_lvl;
}
