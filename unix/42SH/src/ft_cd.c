/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:29:39 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 20:36:33 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <unistd.h>
#include <libft.h>
#include <ftsh.h>
#include <ftcd.h>

static int	ft_cd_usage(char **cmd, int i)
{
	if (cmd[i] != NULL && cmd[i + 1] != NULL)
	{
		ft_error(FTSH_NAME, "cd", "too many arguments.");
		return (ft_error("usage", FTSH_BLT_USAGE, NULL));
	}
	return (0);
}

static int	ft_cd_check_opts(char *str, char *opts)
{
	int			i;
	char		tmp[20];

	i = 1;
	ft_bzero(tmp, 20);
	while (str[i] != '\0')
	{
		if (ft_strichr(FTSH_BLT_OPTS, str[i]) >= 0)
		{
			if (ft_strichr(opts, str[i]) < 0)
				opts[ft_strlen(opts)] = str[i];
		}
		else
		{
			ft_strcpy(tmp, "illegal option -- ");
			tmp[18] = str[i];
			ft_error("cd", tmp, NULL);
			return (ft_error("Usage", FTSH_BLT_USAGE, NULL));
		}
		i++;
	}
	return (0);
}

static int	ft_cd_get_opts(char **cmd, char *opts)
{
	int			i;

	i = 1;
	while (cmd[i] != NULL)
	{
		if (ft_strcmp(cmd[i], "-") == 0 || ft_strichr(cmd[i], '-') != 0)
			return (i);
		if (ft_strcmp(cmd[i], "--") == 0)
			return (i + 1);
		if (ft_cd_check_opts(cmd[i], opts) != 0)
			return (-1);
		i++;
	}
	return (i);
}

static void	ft_cd_cpy(char *cwd, char *new, char *str)
{
	ft_strcpy(new, cwd);
	ft_strcat(new, "/");
	ft_strcat(new, str);
}

int			ft_cd(t_datas *datas, char **cmd)
{
	int			i;
	char		new[MAXPATHLEN];
	char		opts[FTSH_BLT_MAXOPTS + 1];

	if (ft_strcmp(cmd[0], "cd") != 0)
		return (-1);
	ft_bzero(new, MAXPATHLEN);
	ft_bzero(opts, FTSH_BLT_MAXOPTS + 1);
	i = ft_cd_get_opts(cmd, opts);
	if (i == -1 || ft_cd_usage(cmd, i) != 0)
		return (1);
	if (cmd[i] == NULL)
		ft_strcpy(new, ft_getenv(datas->local, "HOME"));
	else if (ft_strcmp(cmd[i], "-") == 0)
		ft_strcpy(new, ft_getenv(datas->local, "OWD"));
	else
	{
		if (ft_strichr(cmd[i], '/') != 0)
			ft_cd_cpy(ft_getenv(datas->local, "CWD"), new, cmd[i]);
		else
			ft_strcpy(new, cmd[i]);
	}
	return (ft_cd_set(datas, opts, cmd[i], new));
}
