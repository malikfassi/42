/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/01 05:05:43 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/01 18:38:15 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_FILE_H
# define DISPLAY_FILE_H

#include <unistd.h>
#include <fcntl.h>
int 	rd_cl(int fd, int offset);
void    ft_putstr(char *str);
int		is_numeric(char *str, int offset);
int		errors1(char **argv, int argc);
int		errors2(char **argv, int argc);
int		get_length(char *str);
int		ten_power(int a);
int		to_int(char *str);
#endif
