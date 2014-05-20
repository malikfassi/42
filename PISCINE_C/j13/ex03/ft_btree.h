/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 08:01:28 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/02 22:21:07 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_BTREE_H
#define FT_BTREE_H
#include <stdlib.h>
typedef struct      s_btree
{
	struct s_btree  *right;
	struct s_btree  *left;
	void            *item;
}                   t_btree;

#endif
