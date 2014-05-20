/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromathique.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 03:14:37 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 21:36:43 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATHIQUE_H
# define BISTROMATHIQUE_H
# define SYNTAXE_ERROR_MSG "syntax error\n"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;

typedef struct	s_stack
{
	char			*c;
	struct s_stack	*next;
}				t_stack;

/*
** add.c
*/
char		*addition(char *op1, char *op2, int sign, char **av);
char		*add(char *op1, char *op2, char **av);
/*
** check_av.c
*/
int			check_av(char **av);
int			b_val(char c, char *av1);
/*
** ft_is_in.c
*/
int			c_in_s(char c, char *str);
int			is_op(char c, char *av2);
int			is_pm(char c, char *av2);
int			is_am(char c, char *av2);
int			is_ammdm(char c, char *av2);
/*
** ft_str.c
*/
long long	ft_strlen(char *str);
int			b_strcmp(char *s1, char *s2, char *av1);
int			ft_strcmp(char *s1, char *s2);
void		ft_swap(char **str1, char **str2);
char		*strcat(char *dest, const char *src);
/*
** list.c
*/
t_list		*create_elem(char *data);
void		add_list(t_list **begin_list, char *data);
t_list		*list_last(t_list *begin_list);
/*
** mult.c
*/
char		*mult(char *op1, char *op2, char **av);
/*
** parent.c
*/
void		parse_parent(t_list *lst, char *av2);
int			is_mdm(char c, char *av2);
/*
** parse.c
*/
t_list		*parse(char **av, char *str);
/*
** parse_dep.c
*/
char		*rmv_whtspc(char *str);
char		*p_str(long long size, char *str, long long *i);
char		*p_val(char *str, long long *i, char **av);
char		addmin(char *str, long long *i, char *av2);
void		p_add_list(long long size, char c, char d, t_list **l);
/*
** rpn.c
*/
t_list		*trans_rpn(t_list *list, char **av);
char		*calc_rpn(t_list *rpn, char **av);
/*
** stack.c
*/
t_stack		*push(t_stack *top, char *c);
char		*pull(t_stack **top);
void		free_stack(t_stack **top);
/*
** sub.c
*/
char		*subtraction(char *op1, char *op2, char **av);
char		*sub(char *op1, char *op2, char **av);
/*
** utilities.c
*/
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char *str);
int			max(long long a, long long b);
long long	ft_nb_ws(char *str);
char		*rmv_zero(char *str, int sign, char *av1);

#endif
