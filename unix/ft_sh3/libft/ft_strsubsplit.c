/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 13:11:56 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/26 19:02:06 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int  get_nbwords(char const *s, char c, int str_start, int str_end)
{
	int nb_words;
	int i;

	i = str_start;
	nb_words = 0;
	while (s && *(s + i) && i != str_end)
	{
		while (*(s + i) && *(s + i) == c && i != str_end)
			i++;
		if (*(s + i))
			nb_words++;
		while (*(s + i) && *(s + i) != c && i != str_end)
			i++;
	}
	return (nb_words);
}

char        **ft_strsubsplit(char const *s, char c, int f, int l)
{
	int		start;
	int		end;
	char	**ptr;
	int		i;
	
	start = f;
	end = 0;
	i = 0;
	if (f == l)
		return (NULL);
	ptr = (char **)ft_memalloc(sizeof(*ptr) * (get_nbwords(s, c, f, l) + 1));
	while (ptr && s && get_nbwords(s, c, f, l) - i)
	{
		while (*(s + start) && *(s + start) == c && start + end != l)
			start++;
		while (*(s + start + end) && *(s + start + end) != c 
				&& start + end != l)
			end++;
		if (start == l)
			break ;
		ptr[i] = ft_strsub(s, start, end);
		start += end;
		end = 0;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
