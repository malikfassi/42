/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:47:05 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/08 08:45:16 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static int		ft_pow(int pow)
{
	if (pow == 0)
		return (1);
	return (2 * ft_pow(pow - 1));
}

static void		bin2char(int n)
{
	static int		i = 0;
	static int		nb = 0;

	if (n == 1)
		nb += ft_pow(i);
	i++;
	if (i == 8)
	{
		i = 0;
		ft_putchar(nb);
		nb = 0;
	}
}

static void		ft_sig(int sig)
{
	if (sig == SIG1)
		bin2char(1);
	else
		bin2char(0);
}

int				main(void)
{
	int		pid;

	signal(SIG1, ft_sig);
	signal(SIG0, ft_sig);
	ft_putstr("PID : ");
	pid = (int)getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	while (42)
		pause();
	return (0);
}
