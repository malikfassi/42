/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:59:06 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:05:47 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_move_up(t_datas *datas, t_line *line, char *str)
{
	int		i;

	if (ft_strcmp(str, FTSH_KEY_SHUP) != 0)
		return (-1);
	if (line->y == 0 || line->i - datas->cols < -1
		|| (line->y == 1
			&& (datas->cols - (line->x + 1)) > (datas->cols - line->plen)))
	{
		ft_tputs("bl");
		return (1);
	}
	i = 0;
	while (i++ < datas->cols)
		ft_move_left(datas, line, FTSH_KEY_LEFT);
	return (0);
}
