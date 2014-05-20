/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 02:10:08 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 18:57:33 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

void	ft_prompt_clear(t_datas *datas, t_line *line)
{
	if (line->len == 0)
		return ;
	if (line->i < line->len - 1)
		ft_move_end(datas, line, FTSH_KEY_END);
	while (!(line->x == 0 && line->y == 0))
	{
		ft_move_left(datas, line, FTSH_KEY_LEFT);
		ft_putchar(' ');
		ft_tputs("le");
		if ((line->y == 0 && line->x == datas->cols - line->plen - 1)
			|| (line->y > 0 && line->x == datas->cols - 1))
			ft_tputs("nd");
	}
}
