/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/04 14:58:15 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/04 20:29:39 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVEL_EXPR_H

typedef struct		s_tree
{
	int is_op;
	char op;
	int number;
	struct s_tree	*left;
	struct s_tree	*right;
	
}					t_tree;

typedef struct		s_queue
{
	t_tree	**queue;
	int top;
}					t_queue;

void    empty_queue(t_queue *stack);
void    ft_putstr(char *str);
int		is_empty(t_queue *stack);
void    stack_push(t_queue *stack, t_tree *item, int max_length);
t_tree	*stack_pop(t_queue *stack);
int		get_length(char *str);
int		is_numeric(char c);
char	*ft_strcat (char *dest, char *src);
void	store_in_tree(char* expr, t_tree **root);
int		eval_tree(t_tree *expr_tree);
int		multiplication(int a, int b);
int		division(int a, int b);
int		modulo(int a, int b);
int		addition(int a, int b);
int		substraction(int a, int b);
int		get_len(char *str);
int		ten_power(int a);
int		to_int(char *str);



#endif
