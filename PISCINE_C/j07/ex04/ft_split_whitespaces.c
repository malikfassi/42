/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/25 09:39:26 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/25 23:19:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_length(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0' )
		i++;
	return(i);
}

char	**ft_split_whitespaces(char	*str)
{
	int	begin_word;
	int	end_word;

	begin_word = 0;
	while(str[begin_word] != '\0')
	{
		if(str[begin_word] == ' ' 
			|| str[begin_word] == '\t' 
			|| str[begin_word] == '\n')
		{
			while(str[begin_word] == ' ' 
					|| str[begin_word] == '\t' 
					|| str[begin_word] == '\n')
			{
				begin_word++;
			}
			end_word = begin_word;
			while(str[begin_word] != ' '
				   && str[begin_word] != '\t' 
				   && str[begin_word] != '\n')
				end_word++;
		}	
	}
		
}
