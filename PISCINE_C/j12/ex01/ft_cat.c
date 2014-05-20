/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/01 05:58:31 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/01 19:59:49 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	while (i < argc)
	{
		fd = (argc == 1 || *argv[1] == '-') ? 0 : open(argv[i + 1], O_RDONLY);
		if (fd == -1 && i != 0 && (i != argc - 1 || i == 1 || i == argc))
		{
			ft_putstr("cat: ");
			ft_putstr(argv[i]);
			ft_putstr(": No such file or directory\n");
		}
		rd_cl(fd);
		i++;
	}
	return (0);
}

int	rd_cl(int fd)
{
	int		ret;
	int		buf_size;
	char	buf[11];

	buf_size = 10;
	if (fd == -1)
	{
		return (1);
	}
	ret = read(fd, buf, buf_size);
	while (ret)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ret = read(fd, buf, buf_size);
	}
	if (close(fd) == -1)
	{
		return (1);
	}
	return (0);
}


void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
