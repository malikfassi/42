/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:11:21 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 17:21:32 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCT_H
# define LIBFT_STRUCT_H

# include <string.h>

typedef struct		s_clist
{
	void			*content;
	size_t			content_size;
	struct s_clist	*prev;
	struct s_clist	*next;
}					t_clist;

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

#endif
