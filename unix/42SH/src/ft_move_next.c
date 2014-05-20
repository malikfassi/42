/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:09:41 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:07:26 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static int	ft_move_next_find(t_line *line)
{
	int			i;

	i = line->i;
	while (i != line->len - 1)
	{
		i++;
		if (ft_isspace(line->buf[i]) == 1
			&& ft_isspace(line->buf[i + 1]) == 0)
			return (i);
	}
	return (-2);
}

int			ft_move_next(t_datas *datas, t_line *line, char *str)
{
	int			i;

	if (ft_strcmp(str, FTSH_KEY_SHRIGHT) != 0)
		return (-1);
	if (line->i == line->len - 1 || line->len == 0)
	{
		ft_tputs("bl");
		return (1);
	}
	i = ft_move_next_find(line);
	if (i == -2)
	{
		ft_tputs("bl");
		return (1);
	}
	while (line->i != i)
		ft_move_right(datas, line, FTSH_KEY_RIGHT);
	return (0);
}
