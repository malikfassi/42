/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/19 15:41:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/19 16:56:31 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonctions.c"

void ft_div_mod(int a, int b, int *div, int *mod)
{	ft_putchar('a');
	ft_putnbr(a / b);
	*div = a / b;
	ft_putchar('b');
	*mod = a % b;
}

int main() 
{
	int a = 4;
	int b = 2;
	int div;
	int mod;

	ft_div_mod(a,b,&div,&mod);

	ft_putnbr(a);
	ft_putchar('\n');
	ft_putnbr(b);
	ft_putchar('\n');
	ft_putnbr(div);
	ft_putchar('\n');
	ft_putnbr(mod);
	return(0);
}
