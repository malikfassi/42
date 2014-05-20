/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/29 22:12:44 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/30 22:29:20 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	res = 0;

	i = 0;
	while (i < length - 1 && res <= 0)
	{
		res = f(tab[i],tab[i + 1]);
		i++;
	}
	res = (res <= 0) ? 1 : 0;
	return (res);
}
