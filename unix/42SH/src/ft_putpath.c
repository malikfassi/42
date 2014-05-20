/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 18:10:17 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:54:36 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <ftsh.h>

static int	ft_putpath_gethome(char *buf, char *home, char *path)
{
	int			fd;
	int			len;

	if (home == NULL || ft_strlen(home) == 0)
		return (1);
	fd = open(home, O_RDONLY);
	if (fd < 0)
		return (1);
	fcntl(fd, F_GETPATH, buf);
	close(fd);
	len = ft_strlen(buf);
	if (len == 0)
		return (1);
	return (ft_strncmp(path, buf, len));
}

int			ft_putpath(char **env, char *path, int nl)
{
	int			len;
	int			hlen;
	char		*home;
	char		buf[MAXPATHLEN];

	ft_bzero(buf, MAXPATHLEN);
	if (!path)
		return (0);
	home = ft_getenv(env, "HOME");
	if (ft_putpath_gethome(buf, home, path) == 0)
	{
		hlen = ft_strlen(buf);
		len = ft_strlen(path + hlen) + 1;
		ft_putchar('~');
		ft_putstr(path + hlen);
	}
	else
	{
		len = ft_strlen(path);
		ft_putstr(path);
	}
	while (nl--)
		ft_putchar('\n');
	return (len);
}
