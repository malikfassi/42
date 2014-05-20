/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_readentry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:09:50 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 16:53:18 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ftsh.h>

char		*ft_prompt_readentry(t_datas *datas)
{
	int			i;
	int			ret;
	char		buf[2];

	i = 0;
	while ((ret = read(0, buf, 1)))
	{
		buf[ret] = '\0';
		if (buf[0] == '\n')
		{
			while (datas->prompt.buffer[i] != '\0')
			{
				if (ft_isspace(datas->prompt.buffer[i]) == 0)
					return (datas->prompt.buffer);
				i++;
			}
			ft_bzero(datas->prompt.buffer, FTSH_MAXLEN_LINE);
			return (NULL);
		}
		if (ft_strlen(datas->prompt.buffer) < FTSH_MAXLEN_LINE - 1)
			ft_strcat(datas->prompt.buffer, buf);
	}
	if (ret == 0)
		ft_prompt_ctrld(datas, NULL, FTSH_KEY_CTRLD);
	return (NULL);
}
