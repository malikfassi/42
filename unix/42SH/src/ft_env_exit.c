/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:58:57 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:47:34 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>
#include <ftenv.h>

int		ft_env_exit(t_bltenv *env, int code)
{
	ft_strdel(&(env->exe));
	ft_arrdel(&(env->av));
	ft_arrdel(&(env->ep));
	return (code);
}
