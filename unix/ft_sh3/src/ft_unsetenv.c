/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 17:14:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/19 14:09:17 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

char	**ft_unsetenv(char **cmd)
{
	char	**field;
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	if (len_arr(cmd) != 2)
		ft_putstr("Usage : unsetenv <enVar1>\n");
	if (!*(field = find(ENVP, cmd[1])) || len_arr(cmd) != 2)
		return (ENVP);
	tmp = (char **)ft_memalloc(sizeof(char *) * (len_arr(ENVP)));
	while (i < len_arr(ENVP))
	{
		cmd[1] = ft_strtoupper(cmd[1]);
		if (ft_strncmp(cmd[1], ENVP[i], ft_strlen(cmd[1])))
		{
			tmp[j] = ENVP[i];
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	return (tmp);
}
