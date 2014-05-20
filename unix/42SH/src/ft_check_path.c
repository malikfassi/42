/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:17:22 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/23 17:38:57 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <get_next_line.h>
#include <ftsh.h>

static void	ft_check_path_loop(char **arr, char *new)
{
	int			i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (ft_check_daccess(arr[i]) == 0)
		{
			if (ft_strlen(new) > 0)
				ft_strcat(new, ":");
			ft_strcat(new, arr[i]);
		}
		i++;
	}
}

static char	*ft_check_path_default(void)
{
	int			fd;
	char		*line;
	char		**arr;

	line = NULL;
	arr = NULL;
	fd = open("/etc/paths", O_RDONLY);
	if (fd < 0)
		return (ft_strdup(FTSH_DEFAULT_PATH));
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_check_daccess(line) == 0 && ft_arradd(&arr, line) == 0)
		{
			line = NULL;
			continue ;
		}
		ft_strdel(&line);
	}
	close(fd);
	line = ft_implode(arr, ":");
	ft_arrdel(&arr);
	if (line == NULL)
		return (ft_strdup(FTSH_DEFAULT_PATH));
	return (line);
}

char		*ft_check_path(char *path)
{
	int			len;
	char		*new;
	char		**arr;

	len = ft_strlen(path);
	if (len == 0)
		return (ft_check_path_default());
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	arr = ft_strsplit(path, ':');
	if (arr == NULL)
	{
		ft_strdel(&new);
		return (NULL);
	}
	ft_check_path_loop(arr, new);
	ft_arrdel(&arr);
	if (ft_strlen(new) == 0)
	{
		ft_strdel(&new);
		new = ft_check_path_default();
	}
	return (new);
}
