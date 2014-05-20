/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/18 12:51:15 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/18 21:12:48 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void ft_putchar(char c);

void ft_print_numbers(void)
{
	char first_number = '0';
	char last_number = '9';

	while(first_number <= last_number)
	{
		ft_putchar(first_number);
		first_number++;
	}
}
