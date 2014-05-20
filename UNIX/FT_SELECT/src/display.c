/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 20:53:47 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/10 21:38:46 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <outc.h>
#include <double_circ_list.h>
#include <unistd.h>
#include <termcap.h>

void	rewrite(t_dc_list *list, int *is_selected, int line, int fd)
{
	if (is_selected[line] == 1)
	{
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	}
	tputs(tgetstr("cr", NULL), 1, tputs_putchar);
	write(fd, list->val, ft_strlen(list->val));
	if (is_selected[line] == 1)
		tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

void	new_line(t_dc_list *list, int *is_selected, int line, int fd)
{
	tputs(tgetstr("cr", NULL), 1, tputs_putchar);
	if (is_selected[line] == 1)
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	tputs(tgetstr("us", NULL), 1, tputs_putchar);
	write(fd, list->val, ft_strlen(list->val));
	if (is_selected[line] == 1)
		tputs(tgetstr("me", NULL), 1, tputs_putchar);
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
}

void	display(t_dc_list *lst, int *is_selected, int fd)
{
	t_dc_list	*head;
	int			line;

	line = 0;
	rewrite(lst, is_selected, line, fd);
	line = 1;
	tputs(tgetstr("do", NULL), 1, tputs_putchar);
	head = lst;
	lst = lst->next;
	while (lst != head)
	{
		rewrite(lst, is_selected, line, fd);
		tputs(tgetstr("do", NULL), 1, tputs_putchar);
		lst = lst->next;
		line++;
	}
	lst = lst->next;
	while (lst != head)
	{
		tputs(tgetstr("up", NULL), 1, tputs_putchar);
		lst = lst->next;
	}
	tputs(tgetstr("up", NULL), 1, tputs_putchar);
	new_line(lst, is_selected, 0, fd);
}
