/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 20:55:27 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:36:24 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <outc.h>
#include <termcap.h>
#include <unistd.h>
#include <double_circ_list.h>
#include <keys.h>

void	go_to_up(int *line)
{
	while (*line)
	{
		tputs(tgetstr("up", NULL), 1, tputs_putchar);
		(*line)--;
	}
}

void	go_to_down(int argc, int *line)
{
	while (argc - 2)
	{
		tputs(tgetstr("do", NULL), 1, tputs_putchar);
		argc--;
		(*line)++;
	}
}

void	del_go_up(t_dc_list **list, int *is_selected, int *line, int nb)
{
	while (*line)
	{
		go_up(list, is_selected, line, nb);
		tputs(tgetstr("ho", NULL), 1, tputs_putchar);
		tputs(tgetstr("cd", NULL), 1, tputs_putchar);
	}
}
