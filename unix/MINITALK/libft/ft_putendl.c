/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 01:45:22 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:12:35 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

void	ft_putendl(char const *s)
{
	const char	*ss;

	if (s == NULL)
	{
		ft_putendl("(null)");
		return ;
	}
	ss = s;
	while (*ss)
		ss++;
	write(1, s, (ss - s));
	write(1, "\n", 1);
}
