/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:54:13 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/08 09:05:29 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static int		ft_str_is_num(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static void		char2bin(int serv_pid, char c)
{
	int		bin[8];
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (c % 2 == 0)
			bin[i] = 0;
		else
			bin[i] = 1;
		c = c / 2;
		i--;
	}
	i = 7;
	while (i >= 0)
	{
		usleep(BUFF_TIME);
		if (bin[i] == 0)
			kill((pid_t)serv_pid, SIG0);
		else
			kill((pid_t)serv_pid, SIG1);
		i--;
	}
}

int				main(int ac, char **av)
{
	char	*str;
	int		i;
	char	c;
	int		serv_pid;

	if (ac != 3)
		return (-1);
	if (!ft_str_is_num(av[1]))
	{
		ft_putendl_fd("Error 42 : pid must be numeric and positive", 2);
		return (-1);
	}
	str = av[2];
	serv_pid = ft_atoi(av[1]);
	i = 0;
	while (str[i])
	{
		c = str[i];
		char2bin(serv_pid, c);
		i++;
	}
	char2bin(serv_pid, '\n');
	return (0);
}
