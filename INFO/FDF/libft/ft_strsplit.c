/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 23:16:54 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/27 18:24:25 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

static int	get_nbwords(char const *s, char c)
{
	int	nb_words;
	int	i;

	i = 0;
	nb_words = 0;
	while (s && *(s + i))
	{
		while (*(s + i) && *(s + i) == c)
			i++;
		if (*(s + i))
			nb_words++;
		while (*(s + i) && *(s + i) != c)
			i++;
	}
	return (nb_words);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	start;
	size_t	end;
	char	**ptr;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	ptr = NULL;
	if (!s)
		return (ptr);
	ptr = (char **)ft_memalloc(sizeof(char *) * (get_nbwords(s, c) + 1));
	while (get_nbwords(s, c) - i)
	{
		while (s && *(s + start) && *(s + start) == c)
			start++;
		while (s && *(s + start + end) && *(s + start + end) != c)
			end++;
		ptr[i] = ft_strsub(s, start, end);
		start += end;
		end = 0;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
