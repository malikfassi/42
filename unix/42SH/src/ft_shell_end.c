/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:22:23 by gchateau          #+#    #+#             */
/*   Updated: 2014/02/06 19:29:41 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <libft.h>
#include <ftsh.h>

int			ft_shell_end(t_datas *datas)
{
	if (!FLAG_ISTERM(datas->flags))
		return (0);
	if (tcsetattr(0, TCSANOW, ft_getterm(NULL)) == -1)
		return (ft_error(FTSH_NAME, "can not restore terminal.", NULL));
	return (0);
}
