/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 11:56:13 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/24 11:56:32 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_next_line(int const fd, char **line)
{
	char        *buf;
	int         ret;
	char        *tmp;

	if (!line || fd < 0)
		return (-1);
	buf = ft_strnew(1);
	*line = ft_strnew(1);
	while ((ret = read(fd, buf, 1)) && *buf != '\n')
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(*line, buf);
		free(*line);
		*line = tmp;
	}
	return (0);
}
