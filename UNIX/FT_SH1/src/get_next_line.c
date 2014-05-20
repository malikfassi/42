/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 20:04:20 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/25 15:45:58 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libft.h>

int	get_next_line(int const fd, char **line)
{
	char		*buf;
	int			ret;
	char		*tmp;

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
