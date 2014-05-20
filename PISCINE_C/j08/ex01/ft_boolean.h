/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/26 22:27:23 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/26 23:25:19 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_BOOLEAN_H__
#define __FT_BOOLEAN_H__
#include <unistd.h>
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define EVEN_MSG "J'ai un nombre pair d'arguments.\n"
#define ODD_MSG "J'ai un nombre impair d'arguments.\n"
#define EVEN(x) ((x) % 2 ? 1 : 0) 
typedef int t_bool;
#endif
