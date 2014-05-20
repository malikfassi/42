/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 18:10:17 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 21:35:35 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libft.h>
#include <ftsh.h>

static void	ft_prompt_path(t_datas *datas, int plen)
{
	char	cwd[MAXPATHLEN];

	ft_bzero(cwd, MAXPATHLEN);
	datas->prompt.plen = ft_strlen(FTSH_PROMPT) + plen;
	if (getcwd(cwd, MAXPATHLEN) == NULL)
		return ;
	if (FLAG_ISCOLOR(datas->flags))
	{
		if (!FLAG_ISNOENV(datas->flags))
			ft_putstr(FTSH_HCYAN);
		else
			ft_putstr(FTSH_CYAN);
	}
	datas->prompt.plen += ft_putpath(datas->local, cwd, 0);
}

static void	ft_prompt_display(t_datas *datas)
{
	if (FLAG_ISCOLOR(datas->flags))
		ft_putstr(FTSH_RED);
	ft_putchar('(');
	ft_prompt_path(datas, 2);
	if (FLAG_ISCOLOR(datas->flags))
		ft_putstr(FTSH_RED);
	ft_putchar(')');
	ft_putstr(FTSH_PROMPT);
	if (FLAG_ISCOLOR(datas->flags))
		ft_putstr(FTSH_COLOR_RESET);
}

char		*ft_prompt(t_datas *datas, int entry)
{
	if (!FLAG_ISTERM(datas->flags))
		datas->flags &= ~FLAG_COLOR;
	if (datas->status != 2)
		ft_prompt_display(datas);
	ft_bzero(datas->prompt.buffer, FTSH_MAXLEN_LINE);
	if (entry <= 0)
		return (NULL);
	if (FLAG_ISTERM(datas->flags))
	{
		ft_history_prepare(datas);
		if (datas->prompt.line == NULL)
			return (NULL);
		return (ft_prompt_readkey(datas));
	}
	else if (!FLAG_ISTERM(datas->flags))
		return (ft_prompt_readentry(datas));
	return (NULL);
}
