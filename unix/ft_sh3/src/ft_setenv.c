/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:50:01 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/19 14:08:36 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static char	**create_tmp(char **tmp, char **cmd, int i)
{
	cmd[1] = ft_strtoupper(cmd[1]);
	tmp[i] = ft_strjoin(cmd[1], "=");
	tmp[i] = ft_strjoin(tmp[i], cmd[2]);
	tmp[i + 1] = NULL;
	return (tmp);
}

char		**ft_setenv(char **cmd)
{
	char	**field;
	int		i;
	char	**tmp;

	i = 0;
	if (len_arr(cmd) != 3)
	{
		ft_putstr("Usage : setenv <envVar1 envVar2>\n");
		return (ENVP);
	}
	if (*(field = find(ENVP, cmd[1])))
	{
		*field = ft_strnjoin("", *field, ft_strchr(*field, '=') - *field + 1);
		*field = ft_strjoin(*field, cmd[2]);
		return (ENVP);
	}
	tmp = (char **)ft_memalloc(sizeof(char *) * (len_arr(ENVP) + 2));
	while (i < len_arr(ENVP))
	{
		tmp[i] = ENVP[i];
		i++;
	}
	tmp = create_tmp(tmp, cmd, i);
	return (tmp);
}
