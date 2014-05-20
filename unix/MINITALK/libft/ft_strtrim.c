/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 23:56:37 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:10:10 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "includes/libft.h"

static int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' \
		|| c == ' ')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	const char	*start;
	const char	*end;
	char		*new;
	char		*ptr;

	start = s;
	while (ft_isspace(*start) == 1)
		start++;
	end = start;
	while (*end)
		end++;
	end--;
	while (ft_isspace(*end) == 1)
		end--;
	if (!(new = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	ptr = new;
	while (*start != *end)
		*ptr++ = *start++;
	*ptr++ = *end;
	*ptr = '\0';
	start = NULL;
	end = NULL;
	ptr = NULL;
	return (new);
}
