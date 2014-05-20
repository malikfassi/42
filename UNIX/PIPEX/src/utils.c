/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:25:15 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/31 14:24:09 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <stdlib.h>

char	**find(char **src, char *to_find)
{
	int	i;

	i = 0;
	to_find = ft_strtoupper(to_find);
	while (src[i] && ft_strncmp(src[i], to_find, ft_strlen(to_find)))
		i++;
	return (&(src[i]));
}

int		findi(char **src, char *to_find)
{
	int	i;

	i = 0;
	while (src[i] && ft_strncmp(src[i], to_find, ft_strlen(to_find)))
		i++;
	return (i);
}

char	*ft_strtoupper(char *str)
{
	char	*tmp;
	int		i;

	tmp = ft_strnew(ft_strlen(str));
	i = 0;
	while (*str)
	{
		tmp[i] = ft_toupper(*str);
		str++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int		len_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t len_s2)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	if (!s1)
		s1 = "";
	if (s2
		&& (ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + len_s2 + 1))))
	{
		ft_strcpy(ptr, s1);
		i = (ft_strlen(s1) == 0) ? 0 : ft_strlen(s1) - 1;
		ft_strncat(&ptr[i], s2, len_s2);
	}
	return (ptr);
}
