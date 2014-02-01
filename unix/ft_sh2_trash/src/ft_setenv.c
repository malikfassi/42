/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:50:01 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/27 19:14:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_setenv.h>
#include <utils.h>
#include <libft.h>
#include <ft_env.h>


static char	**create_tmp(char **tmp, char **cmd, int i)
{
	cmd[1] = ft_strtoupper(cmd[1]);
	tmp[i] = ft_strjoin(cmd[1], "=");
	tmp[i] = ft_strjoin(tmp[i], cmd[2]);
	tmp[i + 1] = NULL;
	return (tmp);
}


char	**ft_setenv(char **cmd, char **envp)
{
	char	**field;
	int		i;
	char	**tmp;

	i = 0;
	if (len_arr(cmd) != 3)
	{
		ft_putstr("Usage : setenv <envVar1 envVar2>\n");
		return (envp);
	}
	if (*(field = find(envp, cmd[1])))
	{
		*field = ft_strnjoin("", *field, ft_strchr(*field, '=') - *field + 1);
		*field = ft_strjoin(*field, cmd[2]);
		return (envp);
	}
	tmp = (char **)ft_memalloc(sizeof(char *) * (len_arr(envp) + 2));
	while (i < len_arr(envp))
	{
		tmp[i] = envp[i];
		i++;
	}
	tmp = create_tmp(tmp, cmd, i);
	return (tmp);
}
