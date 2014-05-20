/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_daccess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:17:22 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/14 18:20:31 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include <libft.h>
#include <ftsh.h>

int		ft_check_daccess(char *path)
{
	struct stat		infos;

	if (!path || ft_strlen(path) == 0)
		return (1);
	if (stat(path, &infos) < 0)
		return (1);
	else if (!S_ISDIR(infos.st_mode))
		return (1);
	else if (access(path, F_OK) < 0)
		return (1);
	return (0);
}
