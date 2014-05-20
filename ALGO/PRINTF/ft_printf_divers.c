/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_divers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 19:51:54 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/04 20:52:27 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>
int			ft_print_long(const char *format, int i, va_list ap)
{
	if (format[i + 1] == 'd')
		return (ft_printf_nbr_ld(va_arg(ap, long)));
	return (0);
}

int			ft_printf_char(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int			ft_printf_nbr(int nb)
{
	ft_putnbr(nb);
	return (ft_intlen(nb));
}

int			ft_printf_str(char *str)
{
	if (str == NULL)
		return (ft_printf_str("(null)"));
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int			ft_printf_unbr(unsigned int n)
{
	if (n >= 10)
		return (ft_printf_unbr(n / 10) + ft_printf_unbr(n % 10));
	ft_printf_char(48 + n);
	return (1);
}
