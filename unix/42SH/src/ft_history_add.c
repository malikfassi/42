/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 01:08:44 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/23 18:15:16 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

void	ft_history_add(t_datas *datas, t_line *line)
{
	t_line	*tmp;

	if (!line)
		return ;
	if (line->prev != NULL)
		line->prev->next = line->next;
	if (line->next != NULL)
		line->next->prev = line->prev;
	tmp = (line->prev != NULL ? line->prev : line->next);
	ft_history_del(&tmp);
	datas->prompt.line = NULL;
	line->prev = NULL;
	line->next = datas->prompt.history;
	if (datas->prompt.history != NULL)
		datas->prompt.history->prev = line;
	datas->prompt.history = line;
}
