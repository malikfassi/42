/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 21:01:07 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/25 16:17:34 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_line.h>

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
