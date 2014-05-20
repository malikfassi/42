/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslimane <kslimane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 06:26:17 by kslimane          #+#    #+#             */
/*   Updated: 2014/03/27 19:17:47 by kslimane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			lx_closetok(char **data, t_flags *flags)
{
	int		i;

	i = 0;
	if (flags->token)
	{
		while (data[flags->index][i])
			i++;
		data[flags->index][i] = '\0';
		flags->index++;
		flags->token = 0;
	}
	return (1);
}

int			lx_endinput(char **data, t_flags *flags)
{
	if (flags->quote == 2)
	{
		ft_putendl_fd("42sh : Input line has unclosed simple quotes", 2);
		return (-1);
	}
	else if (flags->quote == 1)
	{
		ft_putendl_fd("42sh : Input line has unclosed double quotes", 2);
		return (-1);
	}
	if (flags->token)
		lx_closetok(data, flags);
	else
		data[flags->index][0] = '\0';
	return (0);
}

void		lx_addtoword(char **data, char c, t_flags *flags)
{
	int		i;

	i = 0;
	if (flags->token)
	{
		while (data[flags->index][i])
			i++;
		data[flags->index][i] = c;
	}
	else
	{
		data[flags->index][0] = c;
		flags->token = 1;
	}
}

int			lx_tokopr(char **data, char *str, t_flags *flags)
{
	int		shift;
	char	*tmp;

	shift = 0;
	if (flags->quote == 0 && lx_count(OPR, str[0]))
	{
		if (flags->token)
			lx_closetok(data, flags);
		shift = (str[1] == str[0] ? 2 : 1);
		tmp = ft_strsub(str, 0, shift);
		free(data[flags->index]);
		data[flags->index++] = tmp;
		return (shift - 1);
	}
	else if (flags->quote && str[0] == ';')
	{
		lx_addtoword(data, str[0], flags);
		return (1);
	}
	return (0);
}

int			lx_flags(char c, t_flags *flags)
{
	if (lx_count(ARGS, c))
	{
		if (c == '"')
			flags->quote = flags->quote == 1 ? 0 : 1;
		else if (c == '\'')
			flags->quote = flags->quote == 2 ? 0 : 2;
		return (1);
	}
	return (0);
}
