/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:22:43 by evilsbol          #+#    #+#             */
/*   Updated: 2014/03/27 19:50:31 by kslimane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include "libft.h"

# define S_NAME	"[msh]"
# define PROMPT "[msh] > "
# define COMMANDS "cd ls cat echo"
# define OPR "<>|&;"
# define ARGS "\"\'\\"
# define BLANK " \t"
# define WORD "<>|&;\\\"\'\\ \t"
# define BSLASH "$`\"\\\n"
# define MAX_SIZE_STR	1024
# define MAX_SIZE_ARG	512

typedef struct	s_flags
{
	int			index;
	int			quote;
	int			token;
}				t_flags;

char			**lx_lexer(char *line);
int				lx_backslash(char **data, char *str, t_flags *flags);
int				lx_squote(char **data, char *str, t_flags *flags);
int				lx_dquote(char **data, char *str, t_flags *flags);
int				lx_endinput(char **data, t_flags *flags);
void			lx_addtoword(char **data, char c, t_flags *flags);
int				lx_closetok(char **data, t_flags *flags);
int				lx_tokopr(char **data, char *str, t_flags *flags);
int				lx_count(char *str, char c);
void			ft_arrayset(char **array, int size);
int				lx_arrsize(char **arr);
char			**lx_arrdup(char **arr);
int				lx_flags(char c, t_flags *flags);
t_flags			*lx_set_flags(void);

#endif
