/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 01:42:43 by gchateau          #+#    #+#             */
/*   Updated: 2014/02/06 04:20:49 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

void	ft_history_del(t_line **aline)
{
	t_line	*tmp;

	if (!aline || *aline == NULL)
		return ;
	while ((*aline)->prev != NULL)
		*aline = (*aline)->prev;
	while (*aline != NULL)
	{
		tmp = *aline;
		*aline = tmp->next;
		if (*aline != NULL)
			(*aline)->prev = NULL;
		free((t_line *)tmp);
	}
}
