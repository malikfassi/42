/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_response.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:33:07 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:57:34 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <libft.h>
#include <ftsh.h>

int		ft_response(t_datas *datas)
{
	int		res;
	char	*tmp;

	tmp = NULL;
	if (WIFEXITED(datas->status))
		tmp = ft_itoa(WEXITSTATUS(datas->status));
	else if (WIFSIGNALED(datas->status))
		tmp = ft_itoa(WTERMSIG(datas->status));
	else if (WIFSTOPPED(datas->status))
		tmp = ft_itoa(WSTOPSIG(datas->status));
	res = ft_setvar(&(datas->local), "?", tmp);
	ft_strdel(&tmp);
	return (res);
}
