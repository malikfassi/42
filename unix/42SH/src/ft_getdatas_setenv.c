/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdatas_setenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:17:22 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 15:59:29 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static char	**ft_getdatas_setenv_fill(char ***aarr, char **local)
{
	size_t		i;
	char		**arr;

	i = 2;
	arr = *aarr;
	while (local[i + 2] != NULL)
	{
		arr[i] = ft_strdup(local[i + 2]);
		if (arr[i] == NULL)
		{
			ft_arrdel(aarr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

char		**ft_getdatas_setenv(char **ep, char **local)
{
	char		**arr;

	if (ep != NULL && ep[0] != NULL)
		return (ft_arrdup(ep));
	arr = ft_arrnew(5);
	if (arr == NULL)
		return (NULL);
	arr[0] = ft_strjoin("PWD=", ft_getenv(local, "CWD"));
	if (arr[0] == NULL)
	{
		ft_arrdel(&arr);
		return (NULL);
	}
	arr[1] = ft_strjoin("OLDPWD=", ft_getenv(local, "OWD"));
	if (arr[1] == NULL)
	{
		ft_arrdel(&arr);
		return (NULL);
	}
	return (ft_getdatas_setenv_fill(&arr, local));
}
