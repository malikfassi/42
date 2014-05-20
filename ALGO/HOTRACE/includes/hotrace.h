/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 01:01:08 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 20:44:16 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# define MAX_LEX_HEIGHT 50
typedef	struct	s_sizetree
{
	int		data;
	int		height;
	int		balance;
	struct s_sizetree	*parent;
	struct s_sizetree	*right;
	struct s_sizetree	*left;
	struct s_lexlist	*lexlist;
}				t_sizetree;
typedef	struct	s_lextree
{
	char	*key;
	char	*value;
	int		len;
	int		height;
	int		balance;
	struct s_lextree	*parent;
	struct s_lextree	*right;
	struct s_lextree	*left;
	struct s_lextree	*subtree_data;
}				t_lextree;
typedef	struct	s_lexlist
{
	t_lextree	*lextree;
	struct s_lexlist	*next;
}				t_lexlist;
t_sizetree	*ft_new_size_tree(int data);
void	ft_rotate_size_treer(t_sizetree *tree);
void	ft_rotate_size_treel(t_sizetree *tree);
t_sizetree	*ft_insert_size_tree(t_sizetree *root, int data);
void	ft_balances_size_tree(t_sizetree *tree);
void	ft_balances_size_tree_root(t_sizetree *root, t_sizetree *top);
t_sizetree	*ft_search_sizetree(t_sizetree *root, int data);
t_lextree	*ft_new_lextree(char *key, char *value);
void	ft_rotate_lex_tree_r(t_lextree *tree);
void	ft_rotate_lex_tree_l(t_lextree *tree);
void	ft_insert_lex_tree(t_lextree *root, t_lextree *elem);
void	ft_balances_lex_tree(t_lextree *tree);
int	ft_lextree_getlevel(t_lextree *root);
t_lextree	*ft_search_lextree(t_lextree *root, char *data);
t_lexlist	*ft_lexlist_new();
t_lexlist	*ft_getlastlex(t_lexlist *lexlist);
void	ft_add_left_lextree(t_lextree *tree, t_lextree *elem);
void	ft_add_right_lextree(t_lextree *tree, t_lextree *elem);
#endif /* !HOTRACE_H */
