/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:06:00 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 20:38:56 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <libft.h>
#include <ftsh.h>
#include <ftcd.h>

int		ft_cd_set(t_datas *datas, char *opts, char *str, char *new)
{
	char	cwd[MAXPATHLEN];

	ft_bzero(cwd, MAXPATHLEN);
	ft_strcpy(cwd, ft_getenv(datas->local, "CWD"));
	ft_realpath(new);
	if (ft_cd_check(new) != 0)
		return (1);
	if ((str != NULL && ft_strcmp(str, "-") != 0)
		|| ft_strichr(opts, 'l') >= 0 || ft_strichr(opts, 'n') >= 0
		|| ft_strichr(opts, 'p') >= 0 || ft_strichr(opts, 'v') >= 0)
		ft_cd_putpath(datas, opts, new);
	return (ft_cd_update(datas, opts, new, cwd));
}
