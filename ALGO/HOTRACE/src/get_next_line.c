/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 20:04:20 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/15 19:49:58 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <tools.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/uio.h>

static char	*ft_strnjoin(char const *s1, char const *s2, size_t len_s2)
{
	char	*ptr;
	int		i;
	int		len;

	ptr = NULL;
	if (!s1)
		s1 = "";
	len = ft_strlen(s1);
	if (s2
		&& (ptr = (char *)malloc(sizeof(char) * (len + len_s2 + 1))))
	{
		ft_strcpy(ptr, s1);
		i = (len == 0) ? 0 : len - 1;
		ft_strncat(&ptr[i], s2, len_s2);
	}
	return (ptr);
}

static int	join_line_buf(char **line, char *buf, char *to_join)
{
	char	*tmp;

	tmp = ft_strnjoin(to_join, buf, ft_strlen(buf));
	if (!tmp)
		return (-1);
	ft_bzero(buf, sizeof(buf));
	*line = tmp;
	return (0);
}

static int	join_line_buf_shifted(char **line, char *buf, char *to_join)
{
	char	*tmp;
	char	*posn;

	posn = ft_strchr(buf, '\n');
	tmp = ft_strnjoin(to_join, buf, posn - buf);
	if (!tmp)
		return (-1);
	ft_strdel(line);
	*line = tmp;
	ft_strncpy(buf, posn + 1, ft_strlen(buf) - (posn - buf));
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	size_t		ret;
	char		empty[1] = {};

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	if (*buf && !ft_strchr(buf, '\n') && join_line_buf(line, buf, empty))
		return (-1);
	else if (*buf)
		return (join_line_buf_shifted(line, buf, empty));
	while (fd >= 0 && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!ft_strchr(buf, '\n'))
		{
			if (join_line_buf(line, buf, *line))
				return (-1);
		}
		else
			return (join_line_buf_shifted(line, buf, *line));
	}
	return (0);
}
