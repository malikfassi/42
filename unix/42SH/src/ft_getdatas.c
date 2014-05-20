/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdatas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:17:22 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 16:36:28 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include <libft.h>
#include <ftsh.h>

static void		ft_getdatas_init2(t_datas *datas, char **ep)
{
	datas->cols = -1;
	datas->rows = -1;
	datas->status = 0;
	datas->flags = FLAG_NULL;
	datas->flags |= FLAG_COLOR;
	if (ep == NULL || ep[0] == NULL)
		datas->flags |= FLAG_NOENV;
	else
		datas->flags &= ~FLAG_NOENV;
	datas->prompt.plen = 0;
	datas->prompt.line = NULL;
	datas->prompt.history = NULL;
	ft_bzero(datas->prompt.buffer, FTSH_MAXLEN_LINE);
	datas->debug = -1;
}

static int		ft_getdatas_init(t_datas *datas, char **ep)
{
	datas->local = ft_getdatas_setlocal(ep);
	if (datas->local == NULL)
		return (1);
	datas->env = ft_getdatas_setenv(ep, datas->local);
	if (datas->env == NULL)
	{
		ft_arrdel(&(datas->local));
		return (1);
	}
	datas->path = ft_strsplit(ft_getenv(datas->local, "PATH"), ':');
	if (datas->path == NULL)
	{
		ft_arrdel(&(datas->local));
		ft_arrdel(&(datas->env));
		return (1);
	}
	return (0);
}

t_datas			*ft_getdatas(char **ep)
{
	static t_datas	datas;
	static t_datas	*ptr;

	if (!ptr)
	{
		if (isatty(STDIN_FILENO) == 0)
			return (NULL);
		if (ft_getdatas_init(&datas, ep) != 0)
			return (NULL);
		ft_getdatas_init2(&datas, ep);
		if (tgetent(NULL, ft_getenv(datas.local, "TERM")) < 1)
		{
			if (tgetent(NULL, "vt100") < 0)
				datas.flags &= ~FLAG_TERM;
			else
				datas.flags |= FLAG_TERM;
		}
		else
			datas.flags |= FLAG_TERM;
		get_env()->fd_in = dup(0);
		get_env()->fd_out = dup(1);
		get_env()->datas = &datas;
		ptr = &datas;
	}
	return (ptr);
}
