/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:46:11 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:06:28 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_move_home(t_datas *datas, t_line *line, char *str)
{
	if (ft_strcmp(str, FTSH_KEY_HOME) != 0)
		return (-1);
	if (line->x == 0 && line->y == 0)
	{
		ft_tputs("bl");
		return (1);
	}
	while (!(line->x == 0 && line->y == 0))
		ft_move_left(datas, line, FTSH_KEY_LEFT);
	return (0);
}
