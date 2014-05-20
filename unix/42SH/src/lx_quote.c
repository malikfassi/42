/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslimane <kslimane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 06:38:39 by kslimane          #+#    #+#             */
/*   Updated: 2014/03/27 18:33:39 by kslimane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			lx_backslash(char **data, char *str, t_flags *flags)
{
	if (str[1] && str[1] == '$')
	{
		lx_addtoword(data, str[0], flags);
		lx_addtoword(data, str[1], flags);
		return (2);
	}
	else if (str[1] && lx_count(WORD, str[1]))
	{
		lx_addtoword(data, str[1], flags);
		return (2);
	}
	flags->quote = 0;
	return (0);
}

int			lx_squote(char **data, char *str, t_flags *flags)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\'')
		lx_addtoword(data, str[i++], flags);
	if (str[i] == '\'')
		flags->quote = 0;
	return (i);
}

int			lx_dquote(char **data, char *str, t_flags *flags)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '"')
	{
		if (str[i] != '\\')
			lx_addtoword(data, str[i], flags);
		else if (str[i] == '\\' && str[i + 1] && lx_count(BSLASH, str[i + 1]))
			lx_addtoword(data, str[++i], flags);
		else if (str[i] == '\\')
			lx_addtoword(data, str[i], flags);
		i++;
	}
	if (str[i] == '"')
		flags->quote = 0;
	return (i);
}
