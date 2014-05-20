/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/19 17:13:36 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/19 17:21:31 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonctions.c"

void ft_putstr(char *str)
{
	int index;
	
	index = 0;
	
	while(str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

int main()
{
	char str[3];
	
	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';

	ft_putstr(&str[0]);
	return(0);
}
