/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 20:00:00 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:46:52 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static size_t	ft_cmdlen(char *s)
{
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	if (*s != '"')
	{
		while (ft_isspace(s[i]) == 0 && s[i] != '\0')
			i++;
		return (i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == '"' && (i > 0 && s[i - 1] != '\\'))
			return (i + 1);
		i++;
	}
	return (i);
}

static size_t	ft_cmdnargs(char *s)
{
	size_t			i;
	size_t			n;

	if (!s)
		return (0);
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) == 0)
		{
			i += ft_cmdlen(s + i);
			n++;
		}
		else if (ft_isspace(s[i]) == 1)
			i++;
	}
	return (n);
}

static char		**ft_cmdsplit_arrdel(char ***arr)
{
	ft_arrdel(arr);
	return (NULL);
}

char			**ft_cmdsplit(char *s)
{
	unsigned int	start;
	size_t			len;
	size_t			i;
	char			**arr;

	if (!s || ft_strlen(s) == 0)
		return (NULL);
	if ((arr = ft_arrnew(ft_cmdnargs(s))) == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (ft_isspace(*s) == 1)
			s++;
		else
		{
			len = (*s != '"' ? ft_cmdlen(s) : ft_cmdlen(s) - 2);
			start = (*s != '"' ? 0 : 1);
			if ((arr[i] = ft_strsub(s, start, len)) == NULL)
				return (ft_cmdsplit_arrdel(&arr));
			i++;
			s += (*s != '"' ? len : len + 2);
		}
	}
	return (arr);
}
