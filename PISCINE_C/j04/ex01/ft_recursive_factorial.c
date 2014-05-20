/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/20 16:27:33 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/22 20:38:29 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	else if (nb < 0 || nb >= 13)
	{
		return (0);
	}
	else
	{
		nb *= ft_recursive_factorial(nb - 1);
		return (nb);
	}
}
