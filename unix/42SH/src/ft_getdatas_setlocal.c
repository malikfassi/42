/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdatas_setlocal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:17:22 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/17 17:43:08 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <unistd.h>
#include <libft.h>
#include <ftsh.h>

static char		**ft_getdatas_setlocal2(char **ep, char **arr)
{
	char			*tmp;

	tmp = ft_check_path(ft_getenv(ep, "PATH"));
	arr[4] = ft_strjoin("PATH=", tmp);
	ft_strdel(&tmp);
	tmp = ft_getenv(ep, "TERM");
	if (tmp == NULL || ft_strlen(tmp) == 0)
		arr[5] = ft_strdup("TERM=vt100");
	else
		arr[5] = ft_strjoin("TERM=", tmp);
	tmp = ft_getenv(ep, "HOME");
	if (ft_check_daccess(tmp) == 0)
		arr[6] = ft_strjoin("HOME=", tmp);
	if (ft_arrsize(arr) < 6)
		ft_arrfree(&arr, 7);
	return (arr);
}

char			**ft_getdatas_setlocal(char **ep)
{
	char			cwd[MAXPATHLEN];
	char			*tmp;
	char			**arr;

	if (getcwd(cwd, MAXPATHLEN) == NULL)
		return (NULL);
	arr = ft_arrnew(7);
	if (arr == NULL)
		return (NULL);
	tmp = ft_itoa(getpid());
	arr[0] = ft_strjoin("$=", tmp);
	ft_strdel(&tmp);
	arr[1] = ft_strdup("?=0");
	tmp = ft_getenv(ep, "PWD");
	if (ft_check_daccess(tmp) == 0)
		arr[2] = ft_strjoin("CWD=", tmp);
	else
		arr[2] = ft_strjoin("CWD=", cwd);
	tmp = ft_getenv(ep, "OLDPWD");
	if (ft_check_daccess(tmp) == 0)
		arr[3] = ft_strjoin("OWD=", tmp);
	else
		arr[3] = ft_strjoin("OWD=", cwd);
	return (ft_getdatas_setlocal2(ep, arr));
}
