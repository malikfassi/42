/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main07.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 16:09:50 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/02 20:53:43 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>


void    *btree_search_item(t_btree *root, void *data_ref,
		        int (*cmpf)(void *, void *));

 int btree_level_count(t_btree *root);
 int get_node_number(t_btree *root, int nb);

void    btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		applyf(root->item);
		printf("go gauche\n");
		btree_apply_prefix(root->left, applyf);
		printf("go droite\n");
		btree_apply_prefix(root->right, applyf);
		printf("done both of %s\n", (char*)root->item);
	}
	else
	{
		printf("going up\n");
	}
}

t_btree *btree_create_node(void *item)
{
	t_btree *tree;

	tree = malloc(sizeof(t_btree));
	if(tree)
	{
		tree->right = 0;
		tree->left = 0;
		tree->item = item;
	}
	return (tree);
}


void ft_putchar(void *chr)
{
	write(1, chr, 1);
}


int  cmp(void * str1, void * str2)
{
	printf(" je check str1 = %s avec str2 = %s\n", (char*)str1, (char*)str2);
	return (*((char*)str1) - *((char*)str2));
}
int main()
{
	t_btree *root;
	t_btree *root1;
	t_btree *root2;
	t_btree *root3;
	t_btree *root4;
	t_btree *root5;

	root = btree_create_node("0");
	root1 = btree_create_node("1");
	root2 = btree_create_node("2");
	root3 = btree_create_node("3");
	root4 = btree_create_node("4");
	root5 = btree_create_node("5");

	root3->left = root2;
	root2->left = root1;
	root1->left = root;
	root3->right = root5;
	root5->left = root4;

	//printf("%d", btree_level_count(root3));
	printf("%d\n",get_node_number(root3, 0));	
	return(0);
}
