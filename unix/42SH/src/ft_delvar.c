/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:33:07 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:57:34 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static void	ft_delvar_del(char **arr, char *key)
{
	size_t		i;
	int			len;
	char		del;

	i = 0;
	del = 0;
	len = ft_strlen(key);
	while (arr[i] != NULL)
	{
		if (del == 1)
			arr[i] = arr[i + 1];
		else
		{
			if (ft_strncmp(arr[i], key, len) == 0 && arr[i][len] == '=')
			{
				ft_strdel(&(arr[i]));
				arr[i] = arr[i + 1];
				del = 1;
			}
		}
		i++;
	}
}

int			ft_delvar(char **arr, char *key)
{
	if (!arr || !key || ft_strlen(key) == 0)
		return (1);
	if (ft_getenv(arr, key) == NULL)
		return (-1);
	ft_delvar_del(arr, key);
	return (0);
}
