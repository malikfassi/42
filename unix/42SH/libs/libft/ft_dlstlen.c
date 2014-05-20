/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:33:07 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:33:08 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlstlen(t_dlist *dlst)
{
	size_t	n;

	if (!dlst)
		return (0);
	n = ft_dlstlen_rwd(dlst);
	n += ft_dlstlen_fwd(dlst);
	return (n - 1);
}
