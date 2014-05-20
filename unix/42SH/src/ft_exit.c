/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:10:51 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 19:06:34 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ftsh.h>

int		ft_exit(t_datas *datas, int code)
{
	ft_shell_end(datas);
	ft_bzero(datas->prompt.buffer, FTSH_MAXLEN_LINE);
	ft_arrdel(&(datas->path));
	ft_arrdel(&(datas->env));
	ft_arrdel(&(datas->local));
	ft_history_del(&(datas->prompt.history));
	if (datas->prompt.line != NULL)
		ft_history_del(&(datas->prompt.line));
	exit(code);
	return (code);
}
