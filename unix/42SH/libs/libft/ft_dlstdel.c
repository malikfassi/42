/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:28:22 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/25 17:48:34 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlist **adlst, void (*del)(void *, size_t))
{
	ft_dlstdel_rwd(adlst, (*del));
	ft_dlstdel_fwd(adlst, (*del));
	ft_dlstdelone(adlst, (*del));
}
