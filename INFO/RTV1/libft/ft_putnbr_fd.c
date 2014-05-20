/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:28:11 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:41:30 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	backward_nb;

	backward_nb = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	while (n > 10)
	{
		backward_nb *= 10;
		backward_nb += n % 10;
		n /= 10;
	}
	while (backward_nb > 0)
	{
		ft_putchar_fd('0' + (backward_nb % 10), fd);
		backward_nb /= 10;
	}
}
