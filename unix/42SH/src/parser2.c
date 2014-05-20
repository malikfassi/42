/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:21:40 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/27 06:32:37 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "libft.h"

int		parser_pipe(t_cmds **current_node, int *is_new_cmd, char **lex,
					t_cmds **cmds)
{
	t_cmds	*tmp;

	tmp = (*current_node);
	(*current_node) = new_cmd();
	(*current_node)->type = PIPE;
	(*current_node)->left = tmp;
	if (tmp->father)
	{
		(*current_node)->father = tmp->father;
		(*current_node)->father->right = (*current_node);
	}
	(*current_node)->left->father = (*current_node);
	(*current_node)->right = new_cmd();
	(*current_node)->right->father = (*current_node);
	(*current_node) = (*current_node)->right;
	*is_new_cmd = TRUE;
	if (!*(lex + 1) || !ft_strcmp(*(lex + 1), "&&")
			|| !ft_strcmp(*(lex + 1), "||") || !ft_strcmp(*(lex + 1), "|")
			|| !ft_strcmp(*(lex + 1), ";"))
	{
		ft_putstr_fd("42sh: parse error near '|'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	return (0);
}

int		parser_lredir(t_cmds **current_node, char **lex, t_cmds **cmds)
{
	if (!*(lex) || !ft_strcmp(*(lex), "&&")
			|| !ft_strcmp(*(lex), "||") || !ft_strcmp(*(lex), "|")
			|| !ft_strcmp(*(lex), ">") || !ft_strcmp(*(lex), "<")
			|| !ft_strcmp(*(lex), ">>") || !ft_strcmp(*(lex), ";"))
	{
		ft_putstr_fd("42sh: parse error near '<'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	add_token((*current_node)->lredir, *lex);
	(*current_node)->type = CMD;
	return (0);
}

int		parser_rredir(t_cmds **current_node, char **lex, t_cmds **cmds)
{
	if (!*(lex) || !ft_strcmp(*(lex), "&&")
			|| !ft_strcmp(*(lex), "||") || !ft_strcmp(*(lex), "|")
			|| !ft_strcmp(*(lex), ">") || !ft_strcmp(*(lex), "<")
			|| !ft_strcmp(*(lex), ">>") || !ft_strcmp(*(lex), ";"))
	{
		ft_putstr_fd("42sh: parse error near '>'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	add_token((*current_node)->rredir, *lex);
	(*current_node)->type = CMD;
	return (0);
}

int		parser_drredir(t_cmds **current_node, char **lex, t_cmds **cmds)
{
	if (!*(lex) || !ft_strcmp(*(lex), "&&")
			|| !ft_strcmp(*(lex), "||") || !ft_strcmp(*(lex), "|")
			|| !ft_strcmp(*(lex), ">") || !ft_strcmp(*(lex), "<")
			|| !ft_strcmp(*(lex), ">>") || !ft_strcmp(*(lex), ";"))
	{
		ft_putstr_fd("42sh: parse error near '>>'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	add_token((*current_node)->drredir, *lex);
	(*current_node)->type = CMD;
	return (0);
}
