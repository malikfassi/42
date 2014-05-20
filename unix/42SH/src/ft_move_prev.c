/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:10:45 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:07:06 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static int	ft_move_prev_find(t_line *line)
{
	int			i;
	int			space;

	i = line->i;
	space = 0;
	while (i != -1)
	{
		if (i != line->i && space == 0 && ft_isspace(line->buf[i]) == 1)
			break ;
		space = ft_isspace(line->buf[i]);
		i--;
		if (i == -1 && space == 1)
			return (-2);
	}
	return (i);
}

int			ft_move_prev(t_datas *datas, t_line *line, char *str)
{
	int			i;

	if (ft_strcmp(str, FTSH_KEY_SHLEFT) != 0)
		return (-1);
	if (line->x == 0 && line->y == 0)
	{
		ft_tputs("bl");
		return (1);
	}
	i = ft_move_prev_find(line);
	if (i == -2)
	{
		ft_tputs("bl");
		return (1);
	}
	while (line->i != i)
		ft_move_left(datas, line, FTSH_KEY_LEFT);
	return (0);
}
