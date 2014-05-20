/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/26 02:43:59 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/26 07:38:30 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_antidote(int i, int j, int k)
{
	if (i > j)
	{
		ft_swap(&i, &j);
	}
	if (i > k)
	{
		ft_swap(&i, &k);
	}
	if (j > k)
	{
		ft_swap(&j, &k);
	}

	return(j);
}
