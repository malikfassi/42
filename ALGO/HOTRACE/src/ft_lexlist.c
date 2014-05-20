/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 06:13:02 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:22:10 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>
#include <stdlib.h>

t_lexlist	*ft_lexlist_new(void)
{
	t_lexlist	*newlist;

	newlist = (t_lexlist*)malloc(sizeof(t_lexlist));
	newlist->lextree = NULL;
	newlist->next = NULL;
	return (newlist);
}

t_lexlist	*ft_getlastlex(t_lexlist *lexlist)
{
	while (lexlist && lexlist->next)
		lexlist = lexlist->next;
	return (lexlist);
}

