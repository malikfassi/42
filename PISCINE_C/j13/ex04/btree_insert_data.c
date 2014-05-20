/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 10:23:49 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/02 22:21:38 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return;
	}
	if (cmpf((*root)->item, item) <= 0)
	{
		if (! (*root)->right)
		{
			(*root)->right = btree_create_node(item);
			return;
		}
		btree_insert_data(&((*root)->right), item, cmpf);
	}
	else
	{
		if (! (*root)->item)
		{
			(*root)->left = btree_create_node(item);
			return;
		}
		btree_insert_data(&((*root)->left), item, cmpf);
	}
}
