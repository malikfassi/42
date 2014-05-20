/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/07 05:04:18 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 19:15:54 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

long long	ft_strlen(char *str)
{
	long long	i;

	i = 0;
	while (str[i] != 0)
	{
		i = i + 1;
	}
	return (i);
}

int			b_strcmp(char *s1, char *s2, char *av1)
{
	long long	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (b_val(s1[i], av1) - b_val(s2[i], av1));
}

int			ft_strcmp(char *s1, char *s2)
{
	long long	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

char	*strcat(char *dest, const char *src)
{
	long long	i;
	long long	j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	j = 0;
	while(src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
