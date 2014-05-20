/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:45:04 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 19:40:43 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools.h>

inline int	ft_strlen(char const *str)
{
	char	*end;

	end = (char *)str;
	while (*end)
		end++;
	return (end - str);
}
