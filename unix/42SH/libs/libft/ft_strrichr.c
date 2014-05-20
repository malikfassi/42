/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrichr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:23:32 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/30 16:28:57 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strrichr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i-- >= 0)
	{
		if (s[i] == (char)c)
			return (i);
	}
	return (-1);
}
