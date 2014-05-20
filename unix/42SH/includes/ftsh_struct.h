/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:09:51 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 22:10:24 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_STRUCT_H
# define FTSH_STRUCT_H

typedef struct		s_cmds
{
	int				type;
	int				flag;
	char			*cmd_path;
	char			**cmd;
	char			**rredir;
	char			**drredir;
	char			**lredir;
	struct s_cmds	*right;
	struct s_cmds	*left;
	struct s_cmds	*father;
}					t_cmds;

typedef struct		s_line
{
	int				i;
	int				x;
	int				y;
	int				len;
	int				plen;
	char			buf[FTSH_MAXLEN_LINE];
	struct s_line	*prev;
	struct s_line	*next;
}					t_line;

typedef struct		s_prompt
{
	int				plen;
	char			buffer[FTSH_MAXLEN_LINE];
	t_line			*line;
	t_line			*history;
}					t_prompt;

typedef struct		s_datas
{
	int				cols;
	int				rows;
	int				status;
	char			**env;
	char			**path;
	char			**local;
	t_prompt		prompt;
	unsigned char	flags;
	int				debug;
}					t_datas;

typedef struct		s_env
{
	int				fd_in;
	int				fd_out;
	char			**envp;
	t_cmds			**cmds;
	t_datas			*datas;
}					t_env;

typedef int			(t_fblt) (t_datas *, char **);

typedef int			(t_fkey) (t_datas *, t_line *, char *);

#endif
