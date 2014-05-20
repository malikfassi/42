/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 03:18:07 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/11 09:45:40 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include "./libft/libft.h"
#include <stdlib.h>
#include <errno.h>


#include <stdio.h>



typedef struct		s_listdirs
{
	char				*name;
	int					is_file;
	struct s_listdirs	*brother;
	struct s_listdirs	*child;
}					t_listdirs;

typedef struct		s_context
{
	int			all;
	int			reverse;
	int			list;
	int			recursive;
	int			time_sort;
	int			print_file_name;
	int			nb_dirs;
	t_listdirs	*dirs_array;
}					t_context;


void	listdirs_addbrother(t_listdirs	**alst, t_listdirs	*new)
{
	if (new && new->name && (*alst) && (*alst)->name)
	new->brother = *alst;
	*alst = new;
}

t_listdirs	*listdirs_new(char	*name, int is_file)
{
	t_listdirs	*new;

	if ((new = (t_listdirs *)malloc(sizeof(t_listdirs))))
	{
		new->name = name;
		new->is_file = is_file;
		new->child = NULL;
		new->brother = NULL;
	}
	return (new);
}

void	listdirs_iter(t_listdirs *lst, void (*f)(t_listdirs* brother))
{
	t_listdirs	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->brother;
	}
}


t_context	*new_context(void)
{
	t_context	*new;

	if ((new = (t_context *)malloc(sizeof(t_context))))
	{
		new->all = 0;
		new->reverse = 0;
		new->list = 0;
		new->recursive = 0;
		new->time_sort = 0;
		new->print_file_name = 1;
		new->nb_dirs = 0;
		new->dirs_array = listdirs_new(NULL, 0);;
	}
	return (new);
}

void	print_file_name(t_listdirs *file)
{
	if (file->name && file->is_file)
		ft_putendl((file->name));
}
void	print_dir_name(t_listdirs *dir)
{
	if (dir->name && !dir->is_file)
		ft_putendl((dir->name));
}

void	swap_list_elem(t_listdirs *elem1, t_listdirs *elem2)
{
	char		*tmp_name;
	t_listdirs	*tmp_child;

	tmp_name = elem1->name;
	tmp_child = elem1->child;

	elem1->name = elem2->name;
	elem1->child = elem2->child;
	
	elem2->name = tmp_name;
	elem2->child = tmp_child;
}

t_listdirs*	reverse_list(t_listdirs *dirs_array)
{
	t_listdirs	*root;
	t_listdirs	*tmp;

	root = NULL;
	
	while (dirs_array && dirs_array->brother)
	{
		tmp = dirs_array->brother;
		dirs_array->brother = root;
		root = dirs_array;
		dirs_array = tmp;
	}
	return (root);
}
void	ascii_sortlist(t_listdirs *dirs_array, int reverse)
{
	t_listdirs	*tmp;
	t_listdirs	*tmp_brother;

	tmp = dirs_array;
	while (tmp && tmp->name)
	{
		tmp_brother = tmp->brother;
		while (tmp_brother && tmp_brother->name)
		{
			if (ft_strcmp(tmp->name, tmp_brother->name) > 0 && !reverse)
			{
				swap_list_elem(tmp, tmp_brother);
			}
			else if (ft_strcmp(tmp->name, tmp_brother->name) < 0 && reverse)
			{
				swap_list_elem(tmp, tmp_brother);
			}
			tmp_brother = tmp_brother->brother;
		}
		tmp = tmp->brother;
	}
}

int	ft_ls(t_context *context)
{
	DIR				*dir;
	struct dirent	*elem;
	struct stat		stat_buf;
	t_listdirs		*tmp;
	int				count;

	count = 0;
	if (context->nb_dirs == 1)
		context->print_file_name = 0;
	tmp = context->dirs_array->brother;
	while (context->nb_dirs - count && tmp)
	{
		if (stat(tmp->name, &stat_buf) == -1)
		{
			perror("stat:");
			return (errno);
		}
		if ((dir = opendir(tmp->name)) && !S_ISREG(stat_buf.st_mode))
		{
			while ((elem = readdir(dir)))
			{
				if (context->all && (elem->d_name)[0] == '.')
				{
					listdirs_addbrother(&(tmp->child), listdirs_new(elem->d_name, 0));
				}
				else if (!((elem->d_name)[0] == '.'))
				{
					listdirs_addbrother(&(tmp->child), listdirs_new(elem->d_name, 0));
				}
			}
			closedir(dir);
		}
		else if (S_ISREG(stat_buf.st_mode))
		{
			tmp->is_file = 1;
			listdirs_addbrother(&(tmp->child), listdirs_new(tmp->name, 1));
		}
		else if (!S_ISREG(stat_buf.st_mode))
		{
			ft_putstr("ls: ");
			perror(tmp->name);
		}
		tmp = tmp->brother;
		count++;
	}
	count = 0;
	tmp = context->dirs_array->brother;
	ascii_sortlist(tmp, context->reverse);
	while (context->nb_dirs - count && tmp)
	{
		if (stat(tmp->name, &stat_buf) == -1)
		{
			perror("stat:");
			return (errno);
		}
		listdirs_iter(tmp->child, &print_file_name);
		tmp = tmp->brother;
		count ++;
	}
	count = 0;
	tmp = context->dirs_array->brother;
	while (context->nb_dirs - count && tmp)
	{
		if (stat(tmp->name, &stat_buf) == -1)
		{
			perror("stat:");
			return (errno);
		}
		if (context->print_file_name && !S_ISREG(stat_buf.st_mode))
		{
			ft_putstr(tmp->name);
			ft_putendl(":");
		}
		ascii_sortlist(tmp->child, context->reverse);
		listdirs_iter(tmp->child, &print_dir_name);
		tmp = tmp->brother;
		count ++;
	}
	return (0);
}


int main(int argc, char **argv)
{
	size_t		i;
	size_t 		j;
	int			nb_dirs;
	t_context	*context;
	t_listdirs	*dirs_array;

	i = 1;
	nb_dirs = argc - 1;
	if (argc)
	{
		context = new_context();
		while ((int)i < argc && argv[i][0] == '-')
		{
			j = 1;
			while (j < ft_strlen(argv[i]))
			{
				if (argv[i][j] == 'a')
					context->all = 1;
				else if (argv[i][j] == 'r')
					context->reverse = 1;
				else if (argv[i][j] == 'l')
					context->list = 1;
				else if (argv[i][j] == 'R')
					context->recursive = 1;
				else if (argv[i][j] == 't')
					context->time_sort = 1;
				else
				{
					ft_putstr("ls: illegal option -- ");
					ft_putchar(argv[i][j]);
					ft_putchar('\n');
					ft_putstr("usage: ls [-Ralrt] [file ...]");
					return (-1);
				}
				j++;
			}
			i++;
		}
		context->nb_dirs = argc - i;
		while (i < argc)
		{
			listdirs_addbrother(&(context->dirs_array->brother), listdirs_new(argv[i++], 0));
		}
		if (context->nb_dirs == 0)
		{
			context->nb_dirs++;
			listdirs_addbrother(&(context->dirs_array->brother), listdirs_new("./", 0));
		}
		ft_ls(context);
	}
	return (0);
}
