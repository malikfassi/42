/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 02:19:47 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/23 18:07:10 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

void	ft_prompt_print(t_datas *datas, t_line *line)
{
	int		i;

	if (!line || line->len == 0)
		return ;
	line->i = 0;
	line->x = 0;
	line->y = 0;
	while (line->buf[line->i] != '\0')
	{
		ft_putchar(line->buf[line->i]);
		line->x++;
		if ((line->y == 0 && line->x == datas->cols - line->plen)
			|| (line->y > 0 && line->x == datas->cols))
		{
			i = 0;
			while (++i < datas->cols)
				ft_tputs("le");
			ft_tputs("do");
			line->x = 0;
			line->y++;
		}
		line->i++;
	}
	line->i--;
}
