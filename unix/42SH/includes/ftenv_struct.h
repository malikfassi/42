/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:07:00 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 22:07:32 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTENV_STRUCT_H
# define FTENV_STRUCT_H

typedef struct	s_bltenv
{
	char		*opts;
	char		*exe;
	char		**av;
	char		**ep;
}				t_bltenv;

#endif
