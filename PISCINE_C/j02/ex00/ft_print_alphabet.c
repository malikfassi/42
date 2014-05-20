/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/18 10:12:24 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/18 21:13:25 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void ft_putchar(char c);

void ft_print_alphabet(void)
{
	char	letter;
	int	i;
	int	max_letter;

	letter = 'a';
	i = 0;
	max_letter = 26;
	while(i < max_letter)
	{
		ft_putchar(letter);
		letter++;
		i++;
	}
}
