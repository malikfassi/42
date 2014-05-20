/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/01 04:30:05 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/01 07:16:36 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		rd_cl(argv[1]);
		return (0);
	}
	else if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	else
	{
		ft_putstr("Too many arguments.\n");
	}
	return (0);
}



int	rd_cl(char *arg)
{
	int		fd;
	int		ret;
	int		buf_size;
	char	buf[11];

	buf_size = 10;
	fd = open(arg, O_RDONLY);
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
