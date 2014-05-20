/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/30 14:51:53 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/30 22:34:46 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DO_OP_H
# define DO_OP_H
#include <unistd.h>

int		get_length(char *str);
int		ten_power(int a);
int		to_int(char *str);
void	ft_print(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
int		errors(char *op, char *b);
int		multiplication(int a, int b);
int		division(int a, int b);
int		modulo(int a, int b);
int		addition(int a, int b);
int		substraction(int a, int b);
int		to_int(char *str);

#endif
