/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_putpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:29:39 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:45:40 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <libft.h>
#include <ftsh.h>

static void	ft_cd_putpath_wrap(t_datas *datas, char *opts, char *path)
{
	int			len;
	char		*home;
	char		tmp[MAXPATHLEN];

	ft_bzero(tmp, MAXPATHLEN);
	if (ft_strichr(opts, 'l') >= 0)
		ft_strncpy(tmp, path, datas->cols - 5);
	else
	{
		home = ft_getenv(datas->local, "HOME");
		len = ft_strlen(home);
		if (home != NULL && len > 0 && ft_strncmp(path, home, len) == 0
			&& (path[len] == '/' || path[len] == '\0'))
		{
			ft_strcpy(tmp, "~");
			if (path[len] != '\0')
				ft_strncat(tmp, (path + len + 1), datas->cols - 6);
		}
		else
			ft_strncpy(tmp, path, datas->cols - 5);
	}
	ft_strcat(tmp, "[...]");
	ft_putendl(tmp);
}

void		ft_cd_putpath(t_datas *datas, char *opts, char *path)
{
	if (ft_strichr(opts, 'n') >= 0 && ft_strichr(opts, 'v') < 0)
		ft_cd_putpath_wrap(datas, opts, path);
	else
	{
		if (ft_strichr(opts, 'v') >= 0)
			ft_putstr("0\t");
		if (ft_strichr(opts, 'l') < 0)
			ft_putpath(datas->local, path, 1);
		else
			ft_putendl(path);
	}
}
