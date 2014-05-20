/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 19:28:15 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 22:35:30 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_H
# define FTSH_H
# define FTSH_NAME				("42sh")
# define FTSH_DEFAULT_PATH		("/bin:/usr/bin")
# define FTSH_MAXLEN_LINE		(1024)
# define FTSH_PROMPT			("-$> ")
# define FTSH_BLACK				("\033[0;30m")
# define FTSH_HBLACK			("\033[1;30m")
# define FTSH_RED				("\033[0;31m")
# define FTSH_HRED				("\033[1;31m")
# define FTSH_GREEN				("\033[0;32m")
# define FTSH_HGREEN			("\033[1;32m")
# define FTSH_YELLOW			("\033[0;33m")
# define FTSH_HYELLOW			("\033[1;33m")
# define FTSH_BLUE				("\033[0;34m")
# define FTSH_HBLUE				("\033[1;34m")
# define FTSH_PURPLE			("\033[0;35m")
# define FTSH_HPURPLE			("\033[1;35m")
# define FTSH_CYAN				("\033[0;36m")
# define FTSH_HCYAN				("\033[1;36m")
# define FTSH_WHITE				("\033[0;37m")
# define FTSH_HWHITE			("\033[1;37m")
# define FTSH_COLOR_RESET		("\033[0m")
# define FTSH_KEY_UP			("\033[A")
# define FTSH_KEY_DOWN			("\033[B")
# define FTSH_KEY_RIGHT			("\033[C")
# define FTSH_KEY_LEFT			("\033[D")
# define FTSH_KEY_END			("\033[F")
# define FTSH_KEY_HOME			("\033[H")
# define FTSH_KEY_SHUP			("\033[1;2A")
# define FTSH_KEY_SHDOWN		("\033[1;2B")
# define FTSH_KEY_SHRIGHT		("\033[1;2C")
# define FTSH_KEY_SHLEFT		("\033[1;2D")
# define FTSH_KEY_CTRLD			("\004")
# define FTSH_KEY_TAB			("\011")
# define FTSH_KEY_CTRLR			("\022")
# define TMP_FILE_L				("/cartmanlikes42L")
# define TMP_FILE_R				("/cartmanlikes42R")
# define CMD					(0)
# define PIPE					(1)
# define AND					(0)
# define OR						(1)
# define UNDEF					(-1)
# define TRUE					(1)
# define FALSE					(0)
# define FLAG_NULL				(0)
# define FLAG_TERM				(1)
# define FLAG_COLOR				(2)
# define FLAG_NOENV				(4)
# define FLAG_ADVERT			(8)

# define FLAG_ISTERM(fl)		((fl & FLAG_TERM) != 0)
# define FLAG_ISCOLOR(fl)		((fl & FLAG_COLOR) != 0)
# define FLAG_ISNOENV(fl)		((fl & FLAG_NOENV) != 0)
# define FLAG_ISADVERT(fl)		((fl & FLAG_ADVERT) != 0)

# include "ftsh_struct.h"
# include "parser.h"
# include <termios.h>

int				ft_error(char *cmd, char *msg, char *arg);
int				ft_shell_start(t_datas *datas);
int				ft_shell_reload(t_datas *datas);
int				ft_shell_end(t_datas *datas);
int				ft_response(t_datas *datas);
int				ft_setvar(char ***aarr, char *key, char *val);
int				ft_delvar(char **arr, char *key);
int				ft_putpath(char **env, char *path, int nl);
int				ft_check_daccess(char *path);
int				ft_echo(t_datas *datas, char **cmd);
int				ft_history(t_datas *datas, char **cmd);
int				ft_exit(t_datas *datas, int code);
int				ft_cd(t_datas *datas, char **cmd);
int				ft_env(t_datas *datas, char **cmd);
int				ft_setenv(t_datas *datas, char **cmd);
int				ft_unsetenv(t_datas *datas, char **cmd);
int				ft_set(t_datas *datas, char **cmd);
int				ft_unset(t_datas *datas, char **cmd);
int				ft_color(t_datas *datas, char **cmd);
int				ft_export(t_datas *datas, char **cmd);
int				ft_tputs(char *s);
int				ft_prompt_nl(t_datas *datas, t_line *line);
int				ft_prompt_ctrld(t_datas *datas, t_line *line, char *str);
int				ft_prompt_ctrlr(t_datas *datas, t_line *line, char *str);
int				ft_prompt_autocomplete(t_datas *datas, t_line *line, char *str);
int				ft_move_left(t_datas *datas, t_line *line, char *str);
int				ft_move_right(t_datas *datas, t_line *line, char *str);
int				ft_move_up(t_datas *datas, t_line *line, char *str);
int				ft_move_down(t_datas *datas, t_line *line, char *str);
int				ft_move_prev(t_datas *datas, t_line *line, char *str);
int				ft_move_next(t_datas *datas, t_line *line, char *str);
int				ft_move_home(t_datas *datas, t_line *line, char *str);
int				ft_move_end(t_datas *datas, t_line *line, char *str);
int				ft_history_prev(t_datas *datas, t_line *line, char *str);
int				ft_history_next(t_datas *datas, t_line *line, char *str);
char			*ft_prompt(t_datas *datas, int entry);
char			*ft_prompt_readentry(t_datas *datas);
char			*ft_prompt_readkey(t_datas *datas);
char			*ft_prompt_return(t_datas *datas, t_line *line);
char			*ft_findexe(char **path, char *exe);
char			*ft_check_path(char *path);
char			*ft_parse_vars(t_datas *datas, char **str);
char			*ft_getenv(char **env, char *key);
char			*ft_getlocal(char **locals, char *key);
char			*ft_getvar(t_datas *datas, char *key);
char			*ft_cmdtrim(char *s);
char			**ft_cmdsplit(char *s);
char			**ft_getdatas_setlocal(char **ep);
char			**ft_getdatas_setenv(char **ep, char **local);
void			ft_magic(t_datas *datas);
void			ft_signal(void);
void			ft_prompt_clear(t_datas *datas, t_line *line);
void			ft_prompt_print(t_datas *datas, t_line *line);
void			ft_prompt_reprint(t_datas *datas, t_line *line, int dc);
void			ft_prompt_addchar(t_datas *datas, t_line *line, char c);
void			ft_prompt_delchar(t_datas *datas, t_line *line, int mode);
void			ft_history_del(t_line **aline);
void			ft_history_add(t_datas *datas, t_line *line);
t_line			*ft_history_prepare(t_datas *datas);
t_line			*ft_history_new(t_datas *datas);
t_datas			*ft_getdatas(char **ep);
struct termios	*ft_getterm(t_datas *datas);

#endif
