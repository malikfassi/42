/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:56:41 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/27 22:10:17 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>
#include <stdlib.h>

char	*replace_tild(char *str)
{
	char	*tmp;
	char	*new_token;

	new_token = ft_strdup(ft_getvar(get_env()->datas, "HOME"));
	tmp = ft_strnew(ft_strlen(str) - 1 + ft_strlen(new_token));
	ft_strcat(tmp, new_token);
	ft_strcat(tmp, str + 1);
	free(new_token);
	return (tmp);
}

char	*replace_dollar(char *str, int j)
{
	int		beg;
	char	*tmp;
	char	*tmp1;
	char	*new_token;

	j++;
	beg = j;
	while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
		j++;
	tmp = ft_strsub(str, beg, j - beg);
	if (!(new_token = ft_strdup(ft_getvar(get_env()->datas, tmp))))
	{
		tmp1 = ft_strnew(ft_strlen(str) - ft_strlen(tmp));
		free(tmp);
		ft_strncat(tmp1, str, beg - 1);
		ft_strcat(tmp1, str + j);
		return (tmp1);
	}
	free(tmp);
	tmp = ft_strnew(ft_strlen(str) - j + beg + ft_strlen(new_token));
	ft_strncat(tmp, str, beg - 1);
	ft_strcat(tmp, new_token);
	ft_strcat(tmp, str + j);
	free(new_token);
	return (tmp);
}

char	*remove_backslash(char *str, int j)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(str));
	ft_strncat(tmp, str, j - 1);
	ft_strcat(tmp, str + j);
	return (tmp);
}

void	replace_var(char **arr)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (j == 0 && arr[i][j] == '~')
				tmp = replace_tild(arr[i]);
			else if ((j != 0 && arr[i][j - 1] != '\\' && arr[i][j] == '$')
					|| (arr[i][j] == '$' && j == 0))
				tmp = replace_dollar(arr[i], j);
			else if ((j != 0 && arr[i][j - 1] == '\\' && arr[i][j] == '$'))
				tmp = remove_backslash(arr[i], j);
			else
				tmp = ft_strdup(arr[i]);
			free(arr[i]);
			arr[i] = tmp;
			j++;
		}
		i++;
	}
}

void	parse_var(t_cmds *tree)
{
	replace_var(tree->cmd);
	replace_var(tree->rredir);
	replace_var(tree->drredir);
	replace_var(tree->lredir);
}
