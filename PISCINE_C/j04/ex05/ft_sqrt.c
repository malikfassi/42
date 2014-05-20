/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/22 12:58:24 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/22 23:20:07 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_square_root(int nb, int i)
{
	if (i <= nb / 2)
	{
		if (nb / i == i && nb % i == 0)
			{
				return (i);
			}
		else
			{
				return (ft_square_root(nb, i + 1));
			}
	}
	return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_square_root(nb, 1));
}
