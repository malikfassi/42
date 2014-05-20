/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:03:46 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:06:10 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_move_down(t_datas *datas, t_line *line, char *str)
{
	int		i;

	if (ft_strcmp(str, FTSH_KEY_SHDOWN) != 0)
		return (-1);
	if (line->i + datas->cols > line->len - 1)
	{
		ft_tputs("bl");
		return (1);
	}
	i = 0;
	while (i++ != datas->cols)
		ft_move_right(datas, line, FTSH_KEY_RIGHT);
	return (0);
}
