/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 00:12:36 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:17:27 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "includes/libft.h"

static size_t	ft_wrd_nb(char const *s, char c)
{
	unsigned int	nb;

	nb = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			nb++;
			while (*s != c && *s)
				s++;
		}
	}
	return (nb);
}

static void		ft_fill_tab(char const *s, char c, char **tab, size_t nb)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < nb)
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[i] != c && s[i])
				i++;
			if (!(tab[k] = ft_strsub(s, j, (i - j))))
				return ;
			k++;
		}
	}
	tab[k] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	nb;
	char			**tab;

	nb = ft_wrd_nb(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	if (tab == NULL)
		return (NULL);
	ft_fill_tab(s, c, tab, nb);
	return (tab);
}
