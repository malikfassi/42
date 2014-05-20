/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:24:15 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/05/04 20:30:07 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define HEX "0123456789abcdef"

# include <string.h>
# include <stdarg.h>


size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int        			 ft_intlen(int n);
int			ft_printf_hex(unsigned int n);
int			ft_print_hex(const char *format, int i, va_list ap);
int         ft_printf_hexm(unsigned int n);
int			ft_printf_hexa(unsigned long n);
int			ft_printf_pointer(void *n);
int			ft_printf_nbr_ld(long n);
int			ft_printf_char(char c);
int			ft_print_long(const char *format, int i, va_list ap);
int			ft_printf_char(char c);
int			ft_printf_nbr(int nb);
int         ft_printf_str(char *str);
int		ft_toupper(int c);
int			ft_printf_type(const char *format, int i, va_list ap);
int			ft_printf_unbr(unsigned int n);
int			ft_printf_octal(unsigned int n);
void		ft_putnbr_lf(double n);
int		ft_printf_nbr_lf(double n);
void	ft_putnbr_ld(long n);

#endif
