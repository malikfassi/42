/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrandom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 21:54:56 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:52:29 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <ftsh.h>

char	*ft_getrandom(char *buf, int len)
{
	int		fd;
	int		res;

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = read(fd, buf, len);
	close(fd);
	if (ret <= 0 || ft_strlen(buf) == 0)
		return (NULL);
	return (buf);
}
