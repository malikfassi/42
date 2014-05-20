/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:21:45 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 16:12:19 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	len_last_dir(char **pwd)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(*pwd);
	while ((*pwd)[len] != '/')
	{
		i++;
		len--;
	}
	return (i);
}

void	cd_tild(char **pwd, char **old_pwd, char **home)
{
	*old_pwd = ft_strjoin("OLDPWD=", *pwd + 3);
	*pwd = ft_strnew(ft_strlen(*home));
	ft_strcpy(*pwd, "PWD=");
	ft_strcpy(*pwd + 3, *home + 4);
}
