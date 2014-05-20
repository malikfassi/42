/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:44:34 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:19:04 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ftsh.h>

static size_t	ft_echo_strlen(char **cmd, size_t start, int nl)
{
	size_t			i;
	size_t			len;

	i = start;
	len = (nl == 0 ? 0 : 1);
	if (!cmd || cmd[start] == NULL)
		return (len);
	while (cmd[i] != NULL)
	{
		len += ft_strlen(cmd[i]);
		if (i != start)
			len += 1;
		i++;
	}
	return (len);
}

static int		ft_echo_putstr(char **cmd, size_t start, int nl)
{
	size_t			i;
	size_t			len;
	int				res;
	char			*tmp;

	i = start;
	res = 0;
	len = ft_echo_strlen(cmd, start, nl);
	if ((tmp = ft_strnew(len)) == NULL)
		return (1);
	while (cmd[i] != NULL)
	{
		if (i != start)
			ft_strcat(tmp, " ");
		ft_strcat(tmp, cmd[i]);
		i++;
	}
	if (nl != 0)
		tmp[len - 1] = '\n';
	res = write(1, tmp, len);
	ft_strdel(&tmp);
	return (res);
}

int				ft_echo(t_datas *datas, char **cmd)
{
	int				nl;
	int				res;
	size_t			start;

	(void)datas;
	if (ft_strcmp(cmd[0], "echo") != 0)
		return (-1);
	res = 0;
	start = 1;
	nl = (cmd[1] != NULL && ft_strcmp(cmd[1], "-n") == 0 ? 0 : 1);
	if (nl == 0)
		start++;
	res = ft_echo_putstr(cmd, start, nl);
	res = (res >= 0 ? 0 : 1);
	return (res);
}
