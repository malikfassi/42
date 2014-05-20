/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_prepare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 00:14:18 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/23 18:16:04 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static t_line	*ft_history_prepare_dupline(t_datas *datas, t_line *line)
{
	t_line			*new;

	new = ft_history_new(datas);
	if (new == NULL)
		return (NULL);
	new->len = line->len;
	ft_strcpy(new->buf, line->buf);
	return (new);
}

t_line			*ft_history_prepare(t_datas *datas)
{
	t_line			*hist;
	t_line			*new;
	t_line			*tmp;

	new = ft_history_new(datas);
	datas->prompt.line = new;
	if (new == NULL)
		return (NULL);
	if (datas->prompt.history == NULL)
		return (new);
	hist = new;
	tmp = datas->prompt.history;
	while (tmp != NULL)
	{
		hist->next = ft_history_prepare_dupline(datas, tmp);
		if (hist->next == NULL)
		{
			ft_history_del(&new);
			return (NULL);
		}
		hist->next->prev = hist;
		hist = hist->next;
		tmp = tmp->next;
	}
	return (new);
}
