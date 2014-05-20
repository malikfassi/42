/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/18 13:14:57 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/18 21:23:19 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void ft_putchar(char c);

void ft_is_negative(int n)
{
	char char_positif;
	char char_negatif;

	char_positif = 'P';
	char_negatif = 'N';
	if(n > 0)
	{	
		ft_putchar(char_positif);
	}
	else
	{
		ft_putchar(char_negatif);
	}
}
