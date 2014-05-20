/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/29 17:48:16 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/30 22:24:00 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * length);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}
