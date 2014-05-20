/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:10:51 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:37:47 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static void	ft_color_putstate(t_datas *datas, int fd)
{
	if (fd <= 0)
		fd = 1;
	ft_putstr_fd(FTSH_NAME, fd);
	ft_putstr_fd(": color is now ", fd);
	if (FLAG_ISCOLOR(datas->flags))
	{
		ft_putstr_fd(FTSH_HGREEN, fd);
		ft_putstr_fd("ON", fd);
	}
	else
	{
		ft_putstr_fd(FTSH_HRED, fd);
		ft_putstr_fd("OFF", fd);
	}
	ft_putendl_fd(FTSH_COLOR_RESET, fd);
}

static int	ft_color_set(t_datas *datas, int state, int fd)
{
	if (FLAG_ISCOLOR(datas->flags) && state == 1)
	{
		ft_putstr_fd(FTSH_NAME, 2);
		ft_putstr_fd(": color is already ", 2);
		ft_putstr_fd(FTSH_HGREEN, 2);
		ft_putstr_fd("ON", 2);
		ft_putendl_fd(FTSH_COLOR_RESET, 2);
		return (1);
	}
	else if (!FLAG_ISCOLOR(datas->flags) && state == 0)
		return (ft_error(FTSH_NAME, "color is already OFF", NULL));
	if (state == 1)
		datas->flags |= FLAG_COLOR;
	else
		datas->flags &= ~FLAG_COLOR;
	ft_color_putstate(datas, fd);
	return (0);
}

int			ft_color(t_datas *datas, char **cmd)
{
	int			state;

	if (ft_strcmp(cmd[0], "color") != 0
		&& ft_strcmp(cmd[0], "setcolor") != 0)
		return (-1);
	if (!FLAG_ISTERM(datas->flags))
		return (ft_error(FTSH_NAME, cmd[0], "terminal not found."));
	if (cmd[1] == NULL)
		state = (FLAG_ISCOLOR(datas->flags) ? 0 : 1);
	else
	{
		cmd[1] = ft_strtoupper(cmd[1]);
		if (ft_strcmp(cmd[1], "ON") == 0)
			state = 1;
		else if (ft_strcmp(cmd[1], "OFF") == 0)
			state = 0;
		else
			state = ft_atoi(cmd[1]);
	}
	state = (state <= 0 ? 0 : 1);
	return (ft_color_set(datas, state, 1));
}
