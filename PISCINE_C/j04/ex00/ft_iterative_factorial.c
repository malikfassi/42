/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/20 15:09:27 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/22 20:31:49 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	if (nb < 0 || nb >= 13)
	{
		return (0);
	}
	while (i <= nb)
	{
		res *= i;
		i++;
	}
	return (res);
}
