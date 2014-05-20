/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/20 17:43:14 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/22 20:46:37 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	if (power < 0)
	{
		return(0);
	}
	else if (power == 0 && nb < 0)
	{
		if( nb < 0)
			return (-1);
		else
			return (1);
	}
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}
