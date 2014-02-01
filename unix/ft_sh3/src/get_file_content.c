/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 11:57:58 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/24 12:22:37 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

char	*get_file_content(int fd)
{
	char        *buf;
	int         ret;
	char        *tmp;
	char		*line;

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
