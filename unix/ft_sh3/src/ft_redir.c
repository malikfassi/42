/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:21:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/26 22:11:47 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <stdio.h>

void	cat_redir(char **cmd)
{
	char	**new_cmd;

	new_cmd = (char **)malloc(sizeof(char *) * 3);
	if (new_cmd)
	{
		new_cmd[0] = "cat";
		new_cmd[1] = *(cmd);
		new_cmd[2] = NULL;
		non_impl_funct(new_cmd);
	}
	else
		ft_putstr_fd("42sh: malloc failed\n", 2);
}

int	no_such_file(char ****cmd, int i)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd((*cmd)[i + 1][0], 2);
	ft_putstr_fd(":no such file or directory\n", 2);
	ft_strdel(&(*cmd)[i + 1][0]);
	ft_strdel(&(*cmd)[i][0]);
	return (-1);
}

int	parse_error(char ****cmd, int i)
{
	if (!(*cmd)[i] || !(*cmd)[i + 1] || ft_strcmp((*cmd)[i][0], "<"))
	{
		ft_putstr_fd("42sh: parse error\n", 2);
		return (-1);
	}
	return (0);
}


void	get_and_write(char *content, int fd, int file_fd)
{
	content = get_file_content(file_fd);
	write(fd, content, ft_strlen(content));
}

int	case_one(char ****cmd, int fd)
{
	int		i;
	int		file_fd;
	char	*content;

	i = 0;
	if (parse_error(cmd, i))
		return (-1);
	while ((*cmd)[i] && (*cmd)[i + 1] && !ft_strcmp((*cmd)[i][0], "<"))
	{
		if ((file_fd = open((*cmd)[i + 1][0], O_RDONLY)) != -1)
		{
			get_and_write(content, fd, file_fd);
			free_arr(&(*cmd)[i]);
			(*cmd)++;
			(*cmd)[i]++;
			if ((*cmd)[i][0])
				break ;
			else
				(*cmd)++;
		}
		else
			return (no_such_file(cmd, i));
		close(file_fd);
	}
	return (0);
}

int	ft_redir_left(char ****cmd)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*content;
	int		file_fd;

	fd = -1;
	tmp = "./tmp";
	if (!ft_strcmp(*(*cmd + 1)[0], "<") || ((!ft_strcmp(*(*cmd)[0], "<")
					&& len_arr((*cmd)[len_arr_triple(*cmd) - 1]) > 1 )))
	{
		fd = open(tmp, O_RDWR | O_CREAT | O_TRUNC);
		if (fd == -1)
		{
			ft_putstr("42sh: open failed\n");
			return (-1);
		}
		chmod(tmp,  S_IRWXU);
		if (!ft_strcmp(*(*cmd)[0], "<"))
		{
			if (case_one(cmd, fd))
				return (-1);
		}
		else
		{
			if (parse_error(cmd, i))
				return (-1);
			while ((*cmd)[i] && (*cmd)[i + 1] && !ft_strcmp((*cmd)[i][0], "<"))
			{
				file_fd = open((*cmd)[i + 1][0], O_RDONLY);
				if (file_fd != -1)
				{
					content = get_file_content(file_fd);
					write(fd, content, ft_strlen(content));
					free_arr(&(*cmd)[i]);
					free_arr(&(*cmd)[i + 1]);
					i += 2;
				}
				else
					return (no_such_file(cmd, i));
				close(file_fd);
			}
		}
		close(fd);
		if ((fd = open(tmp, O_RDONLY)) == -1)
			ft_putstr_fd("42sh: open failed\n", 2);
		if (dup2(fd, 0) == -1)
			ft_putstr_fd("42sh: dup failed\n", 2);
		close(fd);
		//rm tmp
	}
	else if (!ft_strcmp(**cmd[0], "<") && len_arr(*(*cmd + 1)) != 2)
	{
		i = 0;
		cat_redir(*(*cmd + 1));
		(*cmd) += 2;
		while ((*cmd)[i] && (*cmd)[i + 1] && !ft_strcmp((*cmd)[i][0], "<"))
		{
			cat_redir((*cmd)[i + 1]);
			i = 0;
			free_arr(&(*cmd)[i]);
			free_arr(&(*cmd)[i + 1]);
			(*cmd) += 2;
		}
	}
	else
	{
		if ((fd = open(*(*cmd + 1)[0], O_RDONLY)) == -1)
		{
			ft_putstr_fd("42sh: ", 2);
			ft_putstr_fd(*(*cmd + 1)[0], 2);
			ft_putstr_fd(":no such file or directory\n", 2);
			(*cmd)[1][1] = NULL;
		}
		dup2(fd, 0);
		close(fd);
		(*cmd)++;
		(*cmd)[0][0] = (*cmd)[0][1];
		(*cmd)[0][1] = NULL;
	}
	return (0);
}

int	ft_redir_right(char ***cmd, int len_cmd)
{
	int	fd;
	int	i;

	fd = 0;
	i = 1;
	if (!ft_strcmp(*(cmd + len_cmd - 2)[0], ">"))
	{
		fd = open(*(cmd + len_cmd - 1)[0], O_RDWR | O_TRUNC | O_CREAT);
		if (fd == -1)
		{
			ft_putstr_fd("42sh: open failed\n", 2);
			return (-1);
		}
		chmod(ft_strjoin("./", *(cmd + len_cmd - 1)[0]), S_IRWXU);
		dup2(fd, 1);
		close(fd);
		free_arr(&*(cmd + len_cmd - 2));
		free_arr(&*(cmd + len_cmd - 1));
	}
	return (0);
}
