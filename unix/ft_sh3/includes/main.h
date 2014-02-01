/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 21:32:17 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/26 16:28:16 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>

# include <libft.h>

# define BUFF_SIZE 32
# define ENVP get_env()->envp
# define CMDS get_env()->cmds

typedef	struct	s_env
{
	char		****cmds;
	int			fd_in;
	int			fd_out;
	char		**envp;
}				t_env;

t_env	*get_env();
void	set_envp(t_env *env, char ** envp);

/*
**	EXECUTE_COMMANDS
*/

int		implemented_function(char **cmd);
char	*get_path(char **cmd);
void	non_impl_funct(char **cmd);
void	exec_cmds(void);
int		exec_func(char **cmd);
int		ft_pipe(char ***cmd);
int		exec_all_funcs(char ***cmd);
int		ft_redir_left(char ****cmd);
int		ft_redir_right(char ***cmd, int len_cmd);

/*
**	UTILS
*/

void	free_arr(char ***arr);
void	print_arr(char  **arr);
char	**find(char **src, char *to_find);
int		findi(char **src, char *to_find);
int		len_arr(char **arr);
char	*ft_strtoupper(char *str);
char	*ft_strnjoin(char const *s1, char const *s2, size_t len_s2);
int		len_arr_triple(char ***arr);
void    print_arr_triple(char ***arr);
char	*get_file_content(int fd);
/*
**	CD
*/

void	ft_cd(char **cmd);
int		len_last_dir(char **pwd);
void	cd_tild(char **pwd, char **old_pwd, char **home);


/*
**	ENV
*/

void	ft_env();
char	**ft_setenv(char **cmd);
char	**ft_unsetenv(char **cmd);

/*
**	GET_LINE (read stdin)
*/

char	*get_line(void);
int		get_next_line(int const fd, char **line);

/*
**	SEARCH_PATH
*/

char	*reduce_one_slash_front(char *cmd);
char	*search_path(char **paths, char *cmd);

/*
** PARSE_OP
*/

char	***parse_op(char const *s, char **c);

/*
** PARSE_OP
*/

void	signal_gest(void);

/*
** MAIN
*/

void	print_prompt(void);
#endif
