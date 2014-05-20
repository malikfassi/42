/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:32:31 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:56:14 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static char		*ft_setvar_prepare(char *key, char *val)
{
	char			*str;

	if (!key)
		return (NULL);
	str = ft_strnew(ft_strlen(key) + ft_strlen(val) + 1);
	if (str == NULL)
		return (NULL);
	if (ft_strlen(key) > 0)
		ft_strcpy(str, key);
	ft_strcat(str, "=");
	if (val != NULL)
		ft_strcat(str, val);
	return (str);
}

int				ft_setvar(char ***aarr, char *key, char *val)
{
	size_t			i;
	int				len;
	char			*tmp;
	char			**arr;

	i = 0;
	len = ft_strlen(key);
	tmp = ft_setvar_prepare(key, val);
	if (tmp == NULL)
		return (1);
	if (!aarr || *aarr == NULL)
		return (ft_arradd(aarr, tmp));
	arr = *aarr;
	while (arr[i] != NULL)
	{
		if (ft_strncmp(arr[i], key, len) == 0 && arr[i][len] == '=')
		{
			ft_strdel(&(arr[i]));
			arr[i] = tmp;
			return (0);
		}
		i++;
	}
	return (ft_arradd(aarr, tmp));
}
