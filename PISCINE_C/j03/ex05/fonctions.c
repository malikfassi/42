/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/19 11:25:38 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/19 13:49:06 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putnbr(int nb)
{	int backward_nb;


	backward_nb = 0;
	
	if(nb < 0)
	{	
		ft_putchar('-');
		nb = -nb;
	}
	

	while(nb>0)
	{
		backward_nb *= 10;
		backward_nb += nb % 10;
		nb /= 10;
	}

	while(backward_nb > 0)
	{
		ft_putchar('0' + (backward_nb % 10) );
		backward_nb /= 10;
	}
}
