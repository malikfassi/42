/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 19:28:15 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 22:08:55 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTENV_H
# define FTENV_H
# define FTSH_BLT_OPTS		("i")
# define FTSH_BLT_USAGE		("env [-i] [name=value ...] ")
# define FTSH_BLT_USAGE2	("[utility [argument ...]]")
# define FTSH_BLT_MAXOPTS	(1)

# include "ftenv_struct.h"

int		ft_env_print(char **env);
int		ft_env_exit(t_bltenv *env, int code);
int		ft_env_exec(t_datas *datas, t_bltenv *env);
int		ft_env_setav(t_bltenv *env, char **cmd, int i);
int		ft_env_setep(t_datas *datas, t_bltenv *env, char **cmd, int i);

#endif
