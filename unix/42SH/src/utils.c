/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 06:35:07 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/27 22:09:57 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <ftsh.h>
#include <libft.h>
#include <sys/stat.h>

char	*get_tmpdir(char *file, char *buf)
{
	int	fd;

	fd = open("/tmp", O_RDONLY);
	fcntl(fd, F_GETPATH, buf);
	close(fd);
	ft_strcat(buf, file);
	return (buf);
}

void	parser_new_cmd(t_cmds **current_node, int *is_new_cmd, char **lex)
{
	if (*is_new_cmd)
	{
		(*current_node)->cmd = new_arr(len_cmd(lex));
		(*current_node)->rredir = new_arr((nb_item(lex, ">")) + 1);
		(*current_node)->lredir = new_arr((nb_item(lex, "<")) + 1);
		(*current_node)->drredir = new_arr((nb_item(lex, ">>")) + 1);
		*is_new_cmd = FALSE;
	}
}

int		check_open(char *exe)
{
	struct stat	infos;

	if (stat(exe, &infos) < 0)
		return (ft_error(FTSH_NAME, "no such file or directory", exe));
	else if (!S_ISREG(infos.st_mode))
		return (ft_error(FTSH_NAME, exe, "is not a file."));
	else if (access(exe, R_OK) < 0)
		return (ft_error(FTSH_NAME, "permission denied", exe));
	return (0);
}
