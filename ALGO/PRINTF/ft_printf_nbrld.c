/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 19:48:24 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/04 19:56:54 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int			ft_printf_nbr_ld(long n)
{
	if (n == -9223372036854775807)
		ft_printf_str("-9223372036854775807");
	else if (n < 0)
	{
		n *= -1;
		ft_printf_char('-');
		ft_printf_nbr_ld(n);
	}
	else if (n >= 10)
	{
		ft_printf_nbr_ld(n / 10);
		ft_printf_nbr_ld(n % 10);
	}
	else
		return (ft_printf_char(48 + n));
	return (1);
}
