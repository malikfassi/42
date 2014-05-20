/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_gest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 14:47:10 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/22 18:22:25 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void    signal_ctrl_c(int sig)
{
	(void) sig;
	ft_putstr("\b \b\b \b\n");
	print_prompt();
}

static void    signal_ctrl_z(int sig)
{
	(void) sig;
	ft_putstr("\b \b\b \b");
}

void    signal_gest(void)
{
	signal(SIGINT, signal_ctrl_c);
	signal(SIGTSTP, signal_ctrl_z);
}
