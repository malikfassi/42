/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findexe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 23:17:09 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:16:51 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <libft.h>
#include <ftsh.h>

static int		ft_findexe_start(char *exe)
{
	struct stat		infos;

	if (stat(exe, &infos) < 0)
		return (1);
	else if (!S_ISREG(infos.st_mode))
		return (1);
	else if (access(exe, F_OK) < 0)
		return (1);
	else if (access(exe, X_OK) < 0)
		return (1);
	return (0);
}

static int		ft_findexe_check(char *exe)
{
	struct stat		infos;

	if (stat(exe, &infos) < 0)
		return (ft_error(FTSH_NAME, "command not found", exe));
	else if (!S_ISREG(infos.st_mode))
		return (ft_error(FTSH_NAME, exe, "is not an executable."));
	else if (access(exe, F_OK) < 0)
		return (ft_error(FTSH_NAME, "permission denied", exe));
	else if (access(exe, X_OK) < 0)
		return (ft_error(FTSH_NAME, "permission denied", exe));
	return (0);
}

static char		*ft_findexe_prepare(char *path, char *exe)
{
	char			*str;

	str = ft_strnew(ft_strlen(path) + ft_strlen(exe) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, path);
	ft_strcat(str, "/");
	ft_strcat(str, exe);
	return (str);
}

static char		*ft_findexe_search(char **path, char *exe)
{
	size_t			i;
	DIR				*ptdir;
	struct dirent	*datas;

	i = 0;
	while (path[i] != NULL)
	{
		ptdir = opendir(path[i]);
		if (!ptdir)
			return (NULL);
		while ((datas = readdir(ptdir)) != NULL)
		{
			if (ft_strcmp(datas->d_name, exe) == 0)
			{
				closedir(ptdir);
				return (ft_findexe_prepare(path[i], exe));
			}
		}
		closedir(ptdir);
		i++;
	}
	return (NULL);
}

char			*ft_findexe(char **path, char *exe)
{
	char			*tmp;

	if (ft_findexe_start(exe) == 0)
		return (ft_strdup(exe));
	tmp = ft_findexe_search(path, exe);
	if (tmp == NULL)
		return (NULL);
	if (ft_findexe_check(tmp) != 0)
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	return (tmp);
}
