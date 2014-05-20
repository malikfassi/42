/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 21:25:41 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/12 14:19:49 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <termios.h>
#include <stdlib.h>
#include <outc.h>
#include <unistd.h>

int	init_term(char *buffer, struct termios *term)
{
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	tputs(tgetstr("ti", &buffer), 1, tputs_putchar);
	tputs(tgetstr("vi", &buffer), 1, tputs_putchar);
	return (0);
}

int	kill_term(char *buffer, struct termios *term)
{
	tputs(tgetstr("ve", &buffer), 1, tputs_putchar);
	tputs(tgetstr("te", &buffer), 1, tputs_putchar);
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	close(get_fd());
	return (0);
}
