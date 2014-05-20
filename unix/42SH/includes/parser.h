/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:16:02 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 22:37:54 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		parser_pipe(t_cmds **currnod, int *isnewcmd, char **lex, t_cmds **cmds);
int		parser_lredir(t_cmds **current_node, char **lex, t_cmds **cmds);
int		parser_rredir(t_cmds **current_node, char **lex, t_cmds **cmds);
int		parser_drredir(t_cmds **current_node, char **lex, t_cmds **cmds);
int		implemented_function(t_datas *datas, char **cmd);
int		get_write_file(char *file, int fd);
int		ft_redir_left(t_cmds *tree);
int		ft_redir_right(t_cmds *tree);
int		exec_cmd(t_cmds *tree);
int		exec_tree(t_cmds *tree);
int		nb_semicolon(char **lex);
int		len_cmd(char **lex);
int		nb_item(char **lex, char *item);
int		grand_father(int *p, t_cmds *tree, int pid);
int		ft_pipe(t_cmds *tree);
int		check_open(char *exe);
void	no_such_file(char *file);
void	execution(t_cmds *tree);
void	exec_trees(void);
void	files_drredir(t_cmds *tree);
void	files_rredir(t_cmds *tree);
void	call_child(int *p, t_cmds *tree);
void	call_father(int *p, t_cmds *tree);
void	free_tree(t_cmds **tree);
void	free_all_trees(t_cmds **cmds);
void	go_to_up(t_cmds **cmds);
void	parse_var(t_cmds *cmds);
void	add_token(char **arr, char *token);
void	parser_new_cmd(t_cmds **current_node, int *is_new_cmd, char **lex);
char	*get_file_content(int fd);
char	*get_tmpdir(char *file, char *buf);
char	**new_arr(int size);
t_env	*get_env(void);
t_cmds	*new_cmd(void);
t_cmds	**parser(char **lex);

#endif
