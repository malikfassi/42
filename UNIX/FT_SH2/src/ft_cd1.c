/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:18:26 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/19 14:11:15 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void	cd_back(char **pwd, char **old_pwd)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*pwd) - len_last_dir(pwd));
	ft_strncpy(tmp, *pwd, ft_strlen(*pwd) - len_last_dir(pwd));
	if (ft_strlen(tmp + 4) == 0)
		tmp = "PWD=/";
	if (access(tmp + 4, F_OK || X_OK) == 0)
	{
		*old_pwd = ft_strjoin("OLDPWD=", *pwd + 3);
		*pwd = tmp;
	}
	else
	{
		ft_putstr("cd : no such file or directory : ");
		ft_putendl(reduce_one_slash_front(tmp + 4));
	}
}

static void	cd_front(char **pwd, char **old_pwd, char *path)
{
	char	*tmp;
	char	*tmp_path;

	if (ft_strcmp(*pwd, "PWD=/") == 0)
		*pwd = "PWD=";
	tmp = ft_strjoin(*pwd, "/");
	tmp_path = ft_strjoin(tmp, path);
	ft_strdel(&tmp);
	if (access(tmp_path + 4, F_OK || X_OK) == 0)
	{
		*old_pwd = ft_strjoin("OLDPWD=", *pwd + 3);
		*pwd = tmp_path;
	}
	else
	{
		ft_putstr("cd : no such file or directory : ");
		ft_putendl(reduce_one_slash_front(tmp_path + 4));
	}
}

static void	cd_replace(char **pwd, char **old_pwd, char *path)
{
	if (access(path, F_OK || X_OK) == 0)
	{
		*old_pwd = ft_strjoin("OLDPWD=", *pwd + 3);
		*pwd = ft_strjoin("PWD=", path);
	}
	else
	{
		ft_putstr("cd : no such file or directory : ");
		ft_putendl(reduce_one_slash_front(path));
	}
}

void	execute_cd(char **pwd, char **old_pwd, char *path)
{
	if (ft_strcmp(path, "~") == 0)
		cd_tild(pwd, old_pwd, find(ENVP, "HOME="));
	else if (ft_strcmp(path, "..") == 0)
		cd_back(pwd, old_pwd);
	else if (ft_strcmp(path, "."))
		cd_front(pwd, old_pwd, path);
}

void	ft_cd(char **cmd)
{
	char	**dirs;
	int		i;
	char	**pwd;
	char	**old_pwd;

	i = 0;
	pwd = find(ENVP, "PWD=");
	old_pwd = find(ENVP, "OLDPWD=");
	if (cmd[1])
	{
		if (ft_strncmp(cmd[1], "/", 1) == 0)
			cd_replace(pwd, old_pwd, cmd[1]);
		else
		{
			dirs = ft_strsplit(cmd[1], '/');
			while (dirs[i])
			{
				execute_cd(pwd, old_pwd, dirs[i]);
				i++;
			}
		}
	}
	else
		cd_tild(pwd, old_pwd, find(ENVP, "HOME="));
	chdir(*pwd + 4);
}
