/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:32:44 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/04/19 08:43:36 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_itoa_fillstr(unsigned int n, char *ptr, int i)
{
	if (n > 9)
		ft_itoa_fillstr(n / 10, ptr, i - 1);
	ptr[i] = (n % 10) + '0';
}

char		*ft_itoa(int n)
{
	unsigned int	tmp;
	int				len;
	char			*str;

	tmp = (n < 0) ? (n * -1) : n;
	len = ft_intlen(n);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_itoa_fillstr(tmp, str, len - 1);
	return (str);
}
