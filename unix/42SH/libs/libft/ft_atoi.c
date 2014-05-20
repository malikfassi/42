/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:03:08 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/19 18:54:56 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_isvalid(const char *s, int i)
{
	if (ft_isdigit(s[i]) == 1
		|| (i == 0 && (s[i] == '-' || s[i] == '+')))
		return (1);
	return (0);
}

int			ft_atoi(const char *s)
{
	int		i;
	int		sign;
	int		result;

	if (!s)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(*s) == 1)
		s++;
	while (s[i] != '\0' && ft_atoi_isvalid(s, i) == 1)
	{
		if (i == 0 && s[i] == '-')
			sign = -1;
		if (ft_isdigit(s[i]))
			result = s[i] - '0' + result * 10;
		i += 1;
	}
	return (result * sign);
}
