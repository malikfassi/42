/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:21:40 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/27 22:10:17 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		parser_or(t_cmds **current_node, int *is_new_cmd, char **lex,
				t_cmds **cmds)
{
	(*current_node)->right = new_cmd();
	(*current_node)->right->father = (*current_node);
	(*current_node)->right->flag = OR;
	(*current_node) = (*current_node)->right;
	*is_new_cmd = TRUE;
	if (!*(lex + 1) || !ft_strcmp(*(lex + 1), "&&")
			|| !ft_strcmp(*(lex + 1), "||") || !ft_strcmp(*(lex + 1), "|")
			|| !ft_strcmp(*(lex + 1), ";"))
	{
		ft_putstr_fd("42sh: parse error near '||'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	return (0);
}

int		parser_and(t_cmds **currnod, int *is_new_cmd, char **lex, t_cmds **cmds)
{
	(*currnod)->right = new_cmd();
	(*currnod)->right->father = (*currnod);
	(*currnod)->right->flag = AND;
	(*currnod) = (*currnod)->right;
	*is_new_cmd = TRUE;
	if (!*(lex + 1) || !ft_strcmp(*(lex + 1), "&&")
			|| !ft_strcmp(*(lex + 1), "||") || !ft_strcmp(*(lex + 1), "|")
			|| !ft_strcmp(*(lex + 1), ";"))
	{
		ft_putstr_fd("42sh: parse error near '&&'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	return (0);
}

void	parser_new_cmds(t_cmds ***current_tree, t_cmds **current_node,
						int *is_new_cmds, int *is_new_cmd)
{
	if (*is_new_cmds)
	{
		(*current_tree) = (*current_tree) + 1;
		(*current_node) = new_cmd();
		**current_tree = *current_node;
		*is_new_cmds = FALSE;
		*is_new_cmd = TRUE;
	}
}

int		parser_process(t_cmds **current_node, int *is_new, char ***lex,
						t_cmds **cmds)
{
	int	res;

	res = 0;
	parser_new_cmd(current_node, &is_new[1], *lex);
	if (!ft_strcmp(**lex, ";"))
		is_new[0] = TRUE;
	else if (!ft_strcmp(**lex, "|"))
		res = parser_pipe(current_node, &is_new[1], *lex, cmds);
	else if (!ft_strcmp(**lex, "||"))
		res = parser_or(current_node, &is_new[1], *lex, cmds);
	else if (!ft_strcmp(**lex, "&&"))
		res = parser_and(current_node, &is_new[1], *lex, cmds);
	else if (!ft_strcmp(**lex, "<"))
		res = parser_lredir(current_node, ++(*lex), cmds);
	else if (!ft_strcmp(**lex, ">"))
		res = parser_rredir(current_node, ++(*lex), cmds);
	else if (!ft_strcmp(**lex, ">>"))
		res = parser_drredir(current_node, ++(*lex), cmds);
	else
	{
		(*current_node)->type = CMD;
		add_token((*current_node)->cmd, **lex);
	}
	return (res);
}

t_cmds	**parser(char **lex)
{
	t_cmds	**cmds;
	int		is_new[2];
	t_cmds	**current_tree;
	t_cmds	*current_node;

	if (!lex)
		return (NULL);
	is_new[0] = FALSE;
	is_new[1] = TRUE;
	cmds = (t_cmds **)ft_memalloc(sizeof(t_cmds *) * nb_semicolon(lex));
	*cmds = new_cmd();
	current_tree = cmds;
	current_node = *cmds;
	while (lex && *lex)
	{
		parser_new_cmds(&current_tree, &current_node, &is_new[0], &is_new[1]);
		if (parser_process(&current_node, is_new, &lex, cmds))
			return (NULL);
		lex++;
	}
	go_to_up(cmds);
	return (cmds);
}
