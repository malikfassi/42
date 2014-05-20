/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 20:56:41 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/12 20:04:32 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <outc.h>
#include <libft.h>
#include <go.h>
#include <outc.h>
#include <termcap.h>
#include <display.h>
#include <utils.h>
#include <select.h>
#include <unistd.h>
#include <stdlib.h>

void	go_up(t_dc_list **list, int *is_selected, int *line, int argc)
{
	rewrite(*list, is_selected, *line, get_fd());
	if (*line == 0)
		go_to_down(argc, line);
	else
	{
		tputs(tgetstr("up", NULL), 1, tputs_putchar);
		(*line)--;
	}
	*list = (*list)->prev;
	new_line(*list, is_selected, *line, get_fd());
}

void	go_down(t_dc_list **list, int *is_selected, int *line, int argc)
{
	rewrite(*list, is_selected, *line, get_fd());
	if (*line == argc - 2)
		go_to_up(line);
	else
	{
		tputs(tgetstr("do", NULL), 1, tputs_putchar);
		(*line)++;
	}
	*list = (*list)->next;
	new_line(*list, is_selected, *line, get_fd());
}

int		*ft_delete(int *line, int *nb, t_dc_list **list, int *is_selected)
{
	int	current_line;

	rm_list(list);
	is_selected = update_array(is_selected, *line);
	(*nb)--;
	if (!*list)
		return (is_selected);
	tputs(tgetstr("ho", NULL), 1, tputs_putchar);
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
	current_line = *line;
	del_go_up(list, is_selected, line, *nb);
	*line = current_line;
	tputs(tgetstr("cr", NULL), 1, tputs_putchar);
	display(*list, is_selected, get_fd());
	tputs(tgetstr("ho", NULL), 1, tputs_putchar);
	rewrite(*list, is_selected, 0, get_fd());
	while (*line)
	{
		(*line)--;
		*list = (*list)->next;
	}
	if (current_line != *nb - 1)
		go_to_down(current_line + 2, line);
	new_line(*list, is_selected, *line, get_fd());
	return (is_selected);
}

void	ft_space(int *line, int *is_selected, t_dc_list **list, int nb)
{
	if (!is_selected[*line])
		ft_select(is_selected, *list, *line);
	else
		ft_unselect(*list, *line, is_selected);
	go_down(list, is_selected, line, nb);
}

int		*ft_return(int *line, t_dc_list **list, int *is_selected)
{
	while (*line)
	{
		(*line)--;
		*list = (*list)->prev;
	}
	return (is_selected);
}
