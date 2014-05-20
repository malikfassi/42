/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 02:10:26 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:13:23 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char const	*ss;

	if (s == NULL)
	{
		write(fd, "(null)\n", 7);
		return ;
	}
	ss = s;
	while (*ss)
		ss++;
	write(fd, s, (ss - s));
	write(fd, "\n", 1);
}
