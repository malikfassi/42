/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 15:58:06 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/31 16:17:20 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <stdlib.h>
#include <unistd.h>

void		free_arr(char ***arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while ((*arr)[i])
	{
		ft_strdel(*arr + i);
		i++;
	}
	free(*arr);
	*arr = NULL;
}

char		*get_path(char **envp, char **cmd)
{
	char	**paths;
	char	*path;

	paths = ft_strsplit(envp[0] + 5, ':');
	path = search_path(paths, *cmd);
	free_arr(&paths);
	return (path);
}

int			ft_access(char *path)
{
	if (access(path, F_OK) == -1)
		ft_putstr_fd("open: no such file or directory\n", 2);
	else if (access(path, R_OK) == -1)
		ft_putstr_fd("open: permission denied\n", 2);
	else if (access(path, W_OK) == -1)
		ft_putstr_fd("open: permission denied\n", 2);
	else
		return (1);
	return (0);
}
