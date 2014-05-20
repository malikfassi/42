/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/26 04:45:15 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/26 07:39:56 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
unsigned int	conjecture(unsigned int base, unsigned int n)
{
	if (base == 1)
	{
		return (n);
	}
	else
	{
		if (base % 2 == 0)
		{
			return (conjecture(base / 2, n + 1));
		}
		else
		{
			return (conjecture((base * 3) + 1, n + 1));
		}
	}
}


unsigned int	ft_collatz_conjecture(unsigned int base)
{
	return (conjecture(base, 0));
}
