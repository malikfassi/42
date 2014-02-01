/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 17:26:40 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/26 20:35:20 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void	check_words(char const *s, char **c, int *i, int *nb_words)
{
	if (nb_words && *(s + *i) && ft_strncmp(s + *i, c[3], 2)
				&& ft_strncmp(s + *i, c[4], 2)
				&& ft_strncmp(s + *i, c[0], 1)
				&& ft_strncmp(s + *i, c[1], 1))
		(*nb_words)++;
	while (*(s + *i) && ft_strncmp(s + *i, c[3], 2)
				&& ft_strncmp(s + *i, c[4], 2)
				&& ft_strncmp(s + *i, c[0], 1)
				&& ft_strncmp(s + *i, c[1], 1)
				&& ft_strncmp(s + *i, c[2], 1))
		(*i)++;
}

static void	check_op(char const *s, char **c, int *i, int *nb_words)
{
	if (!ft_strncmp(s + *i, c[3], 2) || !ft_strncmp(s + *i, c[4], 2))
	{
		if (nb_words)
			(*nb_words)++;
		(*i) += 2;
	}
	else if (!ft_strncmp(s + *i, c[0], 1) || !ft_strncmp(s + *i, c[1], 1)
			|| !ft_strncmp(s + *i, c[2], 1))
	{
		if (nb_words)
			(*nb_words)++;
		(*i)++;
	}
}
static int  get_nbwords(char const *s, char **c)
{
	int nb_words;
	int i;

	i = 0;
	nb_words = 0;
	while (*(s + i))
	{
		check_op(s, c, &i, &nb_words);
		check_words(s, c, &i, &nb_words);
	}
	return (nb_words);
}

int			check_error_parse(int found)
{
	if (!found)
	{
		ft_putstr_fd("42sh: parse error\n", 2);
		return (-1);
	}
	return (0);
}


void	update_values(char ***ptr, int *i, int *found)
{
	if (ptr[*i])
	{
		(*i)++;
		(*found) = 1;
	}
}


char        ***parse_op(char const *s, char **c)
{
	char	***ptr;
	int		*int_ptr;

	int_ptr = (int *)ft_memalloc(sizeof(int *) * 4);
	ptr = (char ***)ft_memalloc(sizeof(char **) * (get_nbwords(s, c) + 1));
	while (ptr && get_nbwords(s, c) - int_ptr[3])
	{
		int_ptr[2] = 0;
		int_ptr[0] = int_ptr[1];
		check_op(s, c, &int_ptr[1], NULL);
		ptr[int_ptr[3]] = ft_strsubsplit(s, ' ', int_ptr[0], int_ptr[1]);
		update_values(ptr, &int_ptr[3], &int_ptr[2]);
		int_ptr[0] = int_ptr[1];
		check_words(s, c, &int_ptr[1], NULL);
		ptr[int_ptr[3]] = ft_strsubsplit(s, ' ', int_ptr[0], int_ptr[1]);
		update_values(ptr, &int_ptr[3], &int_ptr[2]);
		if (check_error_parse(int_ptr[2]))
			return (NULL);
	}
	ptr[int_ptr[3]] = NULL;
	return (ptr);
}
