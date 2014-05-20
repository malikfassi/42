/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 20:49:40 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:40:31 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <outc.h>
#include <display.h>
#include <termcap.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

void	ft_select(int *is_selected, t_dc_list *list, int line)
{
	is_selected[line] = 1;
	rewrite(list, is_selected, line, get_fd());
}

void	ft_unselect(t_dc_list *list, int line, int *is_selected)
{
	tputs(tgetstr("cr", NULL), 1, tputs_putchar);
	write(get_fd(), list->val, ft_strlen(list->val));
	is_selected[line] = 0;
}
