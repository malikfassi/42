/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 21:01:07 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/19 12:44:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

char	*get_line(void)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret == 0)
		return (line);
	return (NULL);
}
