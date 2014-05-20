/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:16:13 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/27 22:10:12 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <ftsh.h>

char	*get_file_content(int fd)
{
	char	*buf;
	int		ret;
	char	*tmp;
	char	*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	buf = ft_strnew(2048);
	line = ft_strnew(2048);
	while ((ret = read(fd, buf, 2048)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(line, buf);
		free(line);
		line = tmp;
	}
	ft_strdel(&buf);
	return (line);
}

void	no_such_file(char *file)
{
	ft_putstr_fd("42sh: no such file or directory :", 2);
	ft_putendl_fd(file, 2);
}

int		get_write_file(char *file, int fd)
{
	int		file_fd;
	char	*content;

	if (check_open(file) || (file_fd = open(file, O_RDONLY)) == -1)
	{
		close(fd);
		return (-1);
	}
	content = get_file_content(file_fd);
	write(fd, content, ft_strlen(content));
	free(content);
	if (close(file_fd) == -1)
	{
		close(fd);
		return (ft_error(FTSH_NAME, "close failed", NULL));
	}
	return (0);
}

int		ft_redir_left(t_cmds *tree)
{
	int		i;
	int		fd;
	char	buf[MAXPATHLEN];

	if (!tree->lredir || !tree->lredir[0])
		return (0);
	i = 0;
	get_tmpdir(TMP_FILE_L, buf);
	if (!tree->cmd || (tree->cmd && !tree->cmd[0])
		|| (tree->father && tree->father->type != PIPE))
		fd = 1;
	else if ((fd = open(buf, O_RDWR | O_CREAT | O_TRUNC)) == -1
			&& chmod(buf, S_IRWXU))
		return (ft_error(FTSH_NAME, "open failed.", NULL));
	while (tree->lredir[i])
		if (get_write_file(tree->lredir[i++], fd))
			return (-1);
	if (fd != 1)
		close(fd);
	if (fd != 1 && (fd = open(buf, O_RDONLY)) == -1)
		return (ft_error(FTSH_NAME, "open failed.", NULL));
	if (fd != 1 && dup2(fd, 0) == -1)
		return (ft_error(FTSH_NAME, "dup failed.", NULL));
	close(fd);
	return (0);
}

int		ft_redir_right(t_cmds *tree)
{
	int		fd;
	char	buf[MAXPATHLEN];
	char	*content;

	if ((!tree->rredir || (tree->rredir && !tree->rredir[0]))
		&& (!tree->drredir || (tree->drredir && !tree->drredir[0])))
		return (0);
	fd = open(get_tmpdir(TMP_FILE_R, buf), O_RDWR | O_TRUNC | O_CREAT);
	if (fd == -1)
	{
		ft_putstr_fd("42sh: open failed.\n", 2);
		return (-1);
	}
	chmod(buf, S_IRWXU);
	if (!tree->cmd || (tree->cmd && !tree->cmd[0]))
	{
		content = get_file_content(get_env()->fd_in);
		write(fd, content, ft_strlen(content));
		free(content);
	}
	else
		dup2(fd, 1);
	close(fd);
	return (0);
}
