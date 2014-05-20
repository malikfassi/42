/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/19 16:49:00 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/19 17:12:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonctions.c"

void ft_ultimate_div_mod(int *a, int *b)
{	
	if(*b != 0)
	{
		int tmp_a = *a / *b;
		*b = *a % *b;
		*a = tmp_a;
	}
}

int main(){
	int a = 3;
	int b = 2;

	ft_ultimate_div_mod(&a, &b);
	ft_putnbr(a);
	ft_putnbr(b);
	return(0);
}
