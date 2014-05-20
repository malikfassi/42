/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_autocomplete.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:22:23 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 16:52:51 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_prompt_autocomplete(t_datas *datas, t_line *line, char *str)
{
	(void)datas;
	(void)line;
	if (ft_strcmp(str, FTSH_KEY_TAB) != 0)
		return (-1);
	ft_tputs("bl");
	return (0);
}
