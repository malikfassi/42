/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 19:10:05 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/19 12:45:11 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

char	*reduce_one_slash_back(char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	while (cmd[len] != '/')
		len--;
	len--;
	return (ft_strsub(cmd, 0, len + 1));
}

char	*reduce_one_slash_front(char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	while (cmd[len] != '/')
		len--;
	return (ft_strsub(cmd, len + 1, ft_strlen(cmd)));
}

int	find_in_dir(DIR *dir, char *to_find)
{
	struct dirent	*elem;

	while ((elem = readdir(dir)))
	{
		if (ft_strcmp(elem->d_name, to_find) == 0)
			return (1);
	}
	return (0);
}

char	*search_path(char **paths, char *cmd)
{
	DIR				*dir;
	int				i;
	char			*path;

	i = 0;
	while (paths[i] && cmd[1] != '/')
	{
		if ((dir = opendir(paths[i])))
		{
			if (find_in_dir(dir, cmd))
				return (paths[i]);
			closedir(dir);
		}
		i++;
	}
	if (cmd[0] == '/')
		return ("");
	path = reduce_one_slash_back(cmd);
	if (!path)
		return (NULL);
	if ((dir = opendir(path)) && find_in_dir(dir, reduce_one_slash_front(cmd)))
		return (path);
	closedir(dir);
	return (NULL);
}
