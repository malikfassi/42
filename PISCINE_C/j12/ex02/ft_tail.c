/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/01 14:08:39 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/01 19:45:53 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int	errcode;
	int	offset;

	i = 1;
	while (i < argc)
	{
		if (argc >= 2)
		{
			if (argv[1][0] == '-')
			{
				errcode = errors1(argv, argc);
			}
		}
		if (!errcode)
		{
			return (1);
		}
		offset = (is_numeric(argv[1], 2)) ? to_int(&argv[1][2]) : offset;
		offset = (is_numeric(argv[2], 0)) ? to_int(argv[2]) : offset;
		fd = (argc == 1) ? 0 : open(argv[i], O_RDONLY);
		if (fd == -1 && i != 0)
		{
			ft_putstr("tail: ");
			ft_putstr(argv[i]);
			ft_putstr(": No such file or directory\n");
		}
		rd_cl(fd, offset);
		i++;
	}
	return (0);
}



int	rd_cl(int fd, int offset)
{
	int		ret;
	int		buf_size;
	char	buf[11];

	offset = offset;
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
