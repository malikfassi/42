/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 19:33:16 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/04 20:52:54 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int			ft_printf_hex(unsigned int n)
{
	if (n >= 16)
		return (ft_printf_hex(n / 16) + ft_printf_hex(n % 16));
	else
		return (ft_printf_char(HEX[n]));
}

int			ft_print_hex(const char *format, int i, va_list ap)
{
	if (format[i] == 'x')
		return (ft_printf_hex(va_arg(ap, unsigned int)));
	if (format[i] == 'X')
		return (ft_printf_hexm(va_arg(ap, unsigned int)));
	if (format[i] == 'p')
		return (ft_printf_pointer(va_arg(ap, void *)));
	return (1);
}

int			ft_printf_hexm(unsigned int n)
{
	if (n >= 16)
		return (ft_printf_hexm(n / 16) + ft_printf_hexm(n % 16));
	else
		return (ft_printf_char(ft_toupper(HEX[n])));
}

int			ft_printf_hexa(unsigned long n)
{
	if (n >= 16)
		return (ft_printf_hexa(n / 16) + ft_printf_hexa(n % 16));
	else
		return (ft_printf_char(HEX[n]));
}

int			ft_printf_pointer(void *n)
{
	int		i;

	if (n == NULL)
		return (i = ft_printf_str("0x0"));
	i = ft_printf_str("0x");
	return (ft_printf_hexa((unsigned long)n) + i);
}
