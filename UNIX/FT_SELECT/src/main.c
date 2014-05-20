/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:21:20 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/12 19:57:14 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <main.h>
#include <double_circ_list.h>
#include <outc.h>
#include <keys.h>
#include <display.h>
#include <terminal.h>

int		*loop_exec(int *line, int nb, t_dc_list **list, int *is_selected)
{
	char		read_char[5] = {0};

	while (*list)
	{
		while (read_char[0] == 0)
			read(0, read_char, 4);
		if (*(unsigned int *)read_char == ESCAPE)
			break ;
		else if (*(unsigned int *)read_char == UP)
			go_up(list, is_selected, line, nb);
		else if (*(unsigned int *)read_char == DOWN)
			go_down(list, is_selected, line, nb);
		else if (*(unsigned int *)read_char == SPACE)
			ft_space(line, is_selected, list, nb);
		else if (*(unsigned int *)read_char == DELETE
				|| *(unsigned int *)read_char == BACKSPACE)
			is_selected = ft_delete(line, &nb, list, is_selected);
		else if (*(unsigned int *)read_char == RETURN)
			return (ft_return(line, list, is_selected));
		ft_bzero(read_char, 4);
	}
	return (NULL);
}

void	print_result(t_dc_list *list, int line, int *is_selected)
{
	t_dc_list		*head;
	int				before;

	before = 0;
	head = list;
	if (is_selected[line] == 1)
	{
		write(1, (list)->val, ft_strlen((list)->val));
		before = 1;
	}
	list = (list)->next;
	(line)++;
	while (list != head)
	{
		if (is_selected[line] == 1)
		{
			if (before == 1)
				write(1, " ", 1);
			write(1, (list)->val, ft_strlen((list)->val));
			before = 1;
		}
		list = (list)->next;
		(line)++;
	}
}

int		main(int argc, char **argv)
{
	char			buffer[2048];
	struct termios	term;
	t_dc_list		*list;
	int				line;
	int				*is_selected;

	if (argc < 2)
	{
		ft_putstr("Usage : ./ft_select str1 ...\n");
		return (0);
	}
	if (init_term(buffer, &term) == -1)
		return (-1);
	list = fill_list(argc, argv);
	is_selected = (int *)malloc(sizeof(int) * (argc));
	ft_bzero(is_selected, sizeof(int) * argc);
	is_selected[argc - 1] = -1;
	display(list, is_selected, get_fd());
	line = 0;
	is_selected = loop_exec(&line, argc, &list, is_selected);
	kill_term(buffer, &term);
	if (list && is_selected)
		print_result(list, line, is_selected);
	return (0);
}
