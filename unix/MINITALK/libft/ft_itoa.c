/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 00:36:39 by scadoux           #+#    #+#             */
/*   Updated: 2014/02/02 15:11:51 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "includes/libft.h"

char	*ft_itoa(int n)
{
	char			*s;
	int				div;
	unsigned int	i;

	i = 0;
	div = 1;
	if (!(s = (char *)malloc(sizeof(char) * 11)))
		return (NULL);
	if (n == -2147483648)
		s = "-2147483648";
	else if (n < 0)
	{
		n = n * -1;
		s[i++] = '-';
	}
	while ((n / div) > 9 && ++i)
		div *= 10;
	while (n > 9)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	if (n >= 0)
		s[i] = n + '0';
	return (s);
}
