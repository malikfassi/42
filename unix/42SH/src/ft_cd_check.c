/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:29:39 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:45:40 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include <libft.h>
#include <ftsh.h>
#include <ftcd.h>

int		ft_cd_check(char *path)
{
	struct stat	infos;

	if (!path || ft_strlen(path) == 0)
		return (1);
	if (stat(path, &infos) < 0)
		return (ft_error("cd", "no such file or directory", path));
	if (!S_ISDIR(infos.st_mode))
		return (ft_error("cd", path, "is not a directory."));
	if (access(path, F_OK) < 0)
		return (ft_error("cd", "permission denied", path));
	if (chdir(path) < 0)
		return (ft_error("cd", "can not open directory", path));
	return (0);
}
