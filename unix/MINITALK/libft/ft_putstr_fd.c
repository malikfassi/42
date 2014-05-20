/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 02:07:47 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:13:12 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char const	*ss;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return ;
	}
	ss = s;
	while (*ss)
		ss++;
	write(fd, s, (ss - s));
}
