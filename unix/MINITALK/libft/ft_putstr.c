/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 00:52:06 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:12:24 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

void	ft_putstr(char const *s)
{
	const char		*ss;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	ss = s;
	while (*ss)
		ss++;
	write(1, s, (ss - s));
}
