/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 19:22:57 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/17 18:45:53 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <term.h>

static int	ft_tputs_putc(int c)
{
	return (write(1, &c, 1));
}

int			ft_tputs(char *s)
{
	return (tputs(tgetstr(s, NULL), 1, &ft_tputs_putc));
}
