/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <romain.baudot@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/05 15:49:39 by rbaudot           #+#    #+#             */
/*   Updated: 2013/08/09 17:57:09 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromathique.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(48 + n);
	}
}

int			max(long long a, long long b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

long long	ft_nb_ws(char *str)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			nb++;
		}
		i++;
	}
	return (nb);
}

char	*rmv_zero(char *str, int sign, char *av1)
{
	long long	i;
	long long	j;
	long long	len;

	i = (sign) ? 1 : 0;
	len = ft_strlen(str);
	j = i;
	while (str[j] == av1[0] && j < len - 1)
	{
		j++;
	}
	while (j < len)
	{
		str[i] = str[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
