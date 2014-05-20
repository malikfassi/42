/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 20:50:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:39:21 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	get_fd(void)
{
	static int	fd;

	if (fd == 0)
		fd = open(ttyname(0), O_WRONLY);
	return (fd);
}

int	tputs_putchar(int c)
{
	write(get_fd(), &c, 1);
	return (1);
}
