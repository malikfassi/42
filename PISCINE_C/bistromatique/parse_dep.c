/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/09 02:04:29 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 16:22:45 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

char	*rmv_whtspc(char *str)
{
	long long		len;
	long long		spc;
	long long		c[2];
	char			*ret;

	len = ft_strlen(str);
	spc = ft_nb_ws(str);
	ret = (char *)malloc(sizeof(char) * (len - spc + 1));
	c[0] = 0;
	c[1] = 0;
	while (c[0] < len)
	{
		if (str[c[0]] != ' ' && str[c[0]] != '\t' && str[c[0]] != '\n')
		{
			ret[c[1]] = str[c[0]];
			c[1]++;
		}
		c[0]++;
	}
	ret[c[1]] = '\0';
	return (ret);
}

char	*p_str(long long size, char *str, long long *i)
{
	long long	j;
	char		*ret;

	j = 0;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	while (j < size)
	{
		ret[j] = str[*i];
		(*i)++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*p_val(char *str, long long *i, char **av)
{
	long long	j;
	
	j = (str[*i] == av[2][3]) ? *i + 1 : *i;
	while (str[j] && c_in_s(str[j], av[1]))
	{
		j++;
	}
	return (p_str(j - *i, str, i));
}

char	addmin(char *str, long long *i, char *av2)
{
	long long	addmin[2];
	char	c;

	addmin[0] = 0;
	addmin[1] = 0;
	while (str[*i] && is_am(str[*i], av2))
	{
		addmin[0] = (str[*i] == av2[2]) ? addmin[0] + 1 : addmin[0];
		addmin[1] = (str[*i] == av2[3]) ? addmin[1] + 1 : addmin[1];
		(*i)++;
	}
	c = (addmin[1] % 2 == 0) ? av2[2] : av2[3];
	return (c);
}

void	p_add_list(long long size, char c, char d, t_list **l)
{
	char	*data;

	data = (char *)malloc(sizeof(char) * size);
	data[0] = c;
	data[1] = (size > 2) ? d : '\0';
	if (size > 2)
	{
		data[2] = '\0';
	}
	add_list(l, data);
}
