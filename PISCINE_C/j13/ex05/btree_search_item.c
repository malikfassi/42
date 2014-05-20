/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 15:56:52 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/02 22:22:58 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*res;

	res = NULL;
	if (root)
	{
		res = btree_search_item(root->left, data_ref, cmpf);
		if (! cmpf(root->item, data_ref) && ! res)
			return (root -> item);
		if (!res)
		{
		res = btree_search_item(root->right, data_ref, cmpf);
		}
	}
	return (res);
}
