/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:10:51 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/26 19:56:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int			ft_history(t_datas *datas, char **cmd)
{
	int			i;
	t_line		*tmp;

	(void)cmd;
	if (ft_strcmp(cmd[0], "history") != 0)
		return (-1);
	if (datas->prompt.history == NULL)
		return (1);
	tmp = datas->prompt.history;
	while (tmp->next != NULL)
		tmp = tmp->next;
	i = 1;
	while (tmp != NULL)
	{
		if (tmp->buf[0] == '\0')
			continue ;
		ft_putnbr(i);
		ft_putstr("\t: ");
		ft_putstr(tmp->buf);
		ft_putchar('\n');
		tmp = tmp->next;
		i++;
	}
	return (0);
}
