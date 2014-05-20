/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/18 12:43:00 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/18 22:41:59 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void ft_putchar(char c);

void ft_print_reverse_alphabet(void)
{
	char	letter;
	int min_letter;

	letter = 'z';
	min_letter = 26;
	while(min_letter)
	{
		ft_putchar(letter);
		letter--;
		min_letter--;
	}
}
