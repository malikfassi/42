/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:40:39 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/29 22:53:18 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_strsplit_arrsize(char const *s, char c)
{
	size_t	isc;
	size_t	j;
	size_t	n;

	isc = 0;
	j = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[j] != '\0')
	{
		if (s[j] != c && isc == 0)
		{
			isc = 1;
			n++;
		}
		else if (s[j] == c && isc == 1)
			isc = 0;
		j++;
	}
	return (n);
}

static size_t	ft_strsplit_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void		ft_strsplit_freearr(char **arr, size_t i)
{
	while (i--)
		free((void *)arr[i]);
	free((void *)arr);
}

static size_t	ft_strsplit_fillarr(char **arr, char const *s, char c, size_t i)
{
	size_t	len;

	len = ft_strsplit_strlen(s, c);
	arr[i] = ft_strsub(s, 0, len);
	if (arr[i] == NULL)
	{
		ft_strsplit_freearr(arr, i - 1);
		return (0);
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**arr;

	i = 0;
	if (!s || ft_isascii(c) == 0)
		return (NULL);
	arr = ft_memalloc(sizeof(char *) * (ft_strsplit_arrsize(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else if (*s != c)
		{
			if ((len = ft_strsplit_fillarr(arr, s, c, i)) == 0)
				return (NULL);
			s += len;
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
