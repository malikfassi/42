/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getterm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 15:30:22 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/09 17:00:53 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include <libft.h>
#include <ftsh.h>

struct termios		*ft_getterm(t_datas *datas)
{
	static struct termios	back;
	static struct termios	*restore;

	if (restore == NULL)
	{
		if (tcgetattr(0, &back) == -1)
			return (NULL);
		if (datas != NULL)
		{
			datas->cols = tgetnum("co");
			datas->rows = tgetnum("li");
		}
		restore = &back;
	}
	return (restore);
}
