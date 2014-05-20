/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 00:14:18 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 16:57:38 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

char	*ft_prompt_return(t_datas *datas, t_line *line)
{
	int		i;

	i = 0;
	if (line->i != line->len - 1)
		ft_move_end(datas, line, FTSH_KEY_END);
	if (FLAG_ISCOLOR(datas->flags))
		ft_putstr(FTSH_COLOR_RESET);
	ft_tputs("do");
	while (line->buf[i] != '\0')
	{
		if (ft_isspace(line->buf[i]) == 0)
		{
			ft_strcpy(datas->prompt.buffer, line->buf);
			ft_history_add(datas, line);
			return (datas->prompt.buffer);
		}
		i++;
	}
	ft_history_del(&(datas->prompt.line));
	return (NULL);
}
