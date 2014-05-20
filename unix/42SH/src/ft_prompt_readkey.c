/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_readkey.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:22:23 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/27 16:56:14 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ftsh.h>

static void	ft_prompt_readkey_handler(t_datas *datas, char *key)
{
	int				i;
	static t_fkey	*fkey[14] =

	{
	&ft_move_home, &ft_move_end, &ft_history_next, &ft_history_prev,
	&ft_move_left, &ft_move_right, &ft_move_next, &ft_move_prev,
	&ft_move_up, &ft_move_down, &ft_prompt_ctrld,
	&ft_prompt_autocomplete, &ft_prompt_ctrlr, NULL
	};
	if (ft_strlen(key) == 0)
	{
		ft_tputs("bl");
		return ;
	}
	i = 0;
	while (fkey[i] != NULL && (fkey[i])(datas, datas->prompt.line, key) == -1)
		i++;
}

char		*ft_prompt_readkey(t_datas *datas)
{
	char			key[7];

	if (!FLAG_ISNOENV(datas->flags) && FLAG_ISCOLOR(datas->flags))
		ft_putstr(FTSH_HWHITE);
	while (42)
	{
		ft_bzero(key, 7);
		read(0, key, 6);
		if (ft_isprint(key[0]) == 1 && key[1] == 0 && key[2] == 0)
			ft_prompt_addchar(datas, datas->prompt.line, key[0]);
		else if (key[0] == 127 && key[1] == 0 && key[2] == 0)
			ft_prompt_delchar(datas, datas->prompt.line, 0);
		else if (key[0] == 27 && key[1] == 91 && key[2] == 51 && key[3] == 126)
			ft_prompt_delchar(datas, datas->prompt.line, 1);
		else if (key[0] == 10 && key[1] == 0 && key[2] == 0)
		{
			if (ft_prompt_nl(datas, datas->prompt.line) == 0)
				return (ft_prompt_return(datas, datas->prompt.line));
		}
		else
			ft_prompt_readkey_handler(datas, key);
	}
	return (NULL);
}
