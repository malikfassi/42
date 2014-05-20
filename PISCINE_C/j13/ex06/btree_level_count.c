/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 18:56:51 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/02 22:26:34 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"
int	max(int a, int b)
{
	if (a > b)
	{
		return(a);
	}
	return(b);
}


int	btree_level_count(t_btree *root)
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
	{
		return (0);
	}
	return (max(btree_level_count(root->left),
				btree_level_count(root->right)) + 1);
}

