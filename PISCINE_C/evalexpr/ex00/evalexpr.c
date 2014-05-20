/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/04 15:39:25 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/04 20:50:10 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "evalexpr.h"
#include <unistd.h>


void	empty_queue(t_queue *stack)
{
	stack->top = -1;
}

void    ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str, 1);
		i++;
	}
}


int is_empty(t_queue *stack)
{
	int res;

	res = (stack->top == -1) ? 1 : 0;
	return (res);
}

void	stack_push(t_queue *stack, t_tree *item, int max_length)
{
	if (stack->top == (max_length - 1))
	{
		ft_putstr("WARNING : STACK IS FULL\n");
	}
	else
	{
		(stack->top)++;
		stack->queue[stack->top] = item;
	}
}

t_tree *stack_pop(t_queue *stack)
{
	t_tree *removed;
	removed = NULL;
	if (! is_empty(stack))
	{
		removed = (stack->queue)[stack->top];
		(stack->top)--;
	}
	printf("end of ppop top = %d\n", stack->top);
	return (removed);
}


int get_len(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int is_numeric(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

char *ft_strcat (char *dest, char *src)
{
	char *cpy;
	int i;

	cpy = dest;
	i = 0;
	while (*cpy)
	{	
		cpy++;
		i++;
	}
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[++i] = '\0';
	return (cpy);
}

void store_in_tree(char* expr, t_tree **root)
{
	t_queue *stack;
	t_tree *new_node;
	t_tree *op1;
	t_tree *op2;
	char number[100];
	char *item;
	int	length;

	item = &expr[0];
	length = get_len(expr);
	printf("length = %d\n", length);
	stack->queue = malloc(sizeof(t_tree) * length);
	stack->top = 0;
	number[0] = '\0';
	while(*item)
	{
		while(*item == ' ')
		{
			item++;
		}
		if(is_numeric(*item))
		{
			while(is_numeric(*item))
			{
				ft_strcat(number, item);
				item++;
			}
			new_node = malloc(sizeof(t_tree));
			new_node->is_op = 1;
			new_node->number = to_int(number);
			printf("yeah j'ai trouver le chiffre %d\n", new_node->number);
			new_node->left = NULL;
			new_node->right = NULL;
			stack_push(stack, new_node, length);
			number[0] = '\0';
		}
		else
		{
			printf("avant pop %d\n", stack->top);
			op1 = stack_pop(stack);
			printf("apres 1er pop %d\n", stack->top);
			op2 = stack_pop(stack);
			printf("aprees 2ieme pop %d\n", stack->top);
			







			new_node = malloc(sizeof(t_tree));
			new_node->is_op = 0;
			new_node->op = *item;
			new_node->left = op2;
			new_node->right = op1;
			stack_push(stack, new_node, length);
		}
		item++;
		    printf("hey19\n");
	}
	*root = stack_pop(stack);
	    printf("hey20\n");
}

int eval_tree(t_tree *expr_tree)
{
	int op1;
	int op2;
	int (*op[11])(int, int);

	op[0] = &modulo;
	op[5] = &multiplication;
	op[6] = &addition;
	op[8] = &substraction;
	op[10] = &division;

	if( expr_tree->is_op == 0 )
	{
		op1 = eval_tree(expr_tree->left);
		op2 = eval_tree(expr_tree->right);
		return (op[expr_tree->op - 37](op1, op2));
	}
	else
		return (expr_tree->number);
}

//void inorder(struct node *x)
//{
//	if(x != NULL)
//	{
//		inorder(x->left);
//
//		if(x->kind == 'O')
//			printf("%c ",x->op);
//		else
//			printf("%d ",x->number);
//
//		inorder(x->right);
//	}
//}


int main()
{
	t_tree *r;
	printf("hey1\n");
	store_in_tree("100 50 +  2 /", &r);
	printf("hey2\n");
	printf("\nResult = %d\n",eval_tree(r));
	return 0;
}
