/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/30 03:13:49 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/04 17:59:24 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	multiplication(int a, int b)
{
	int	res;

	res = a * b;
	if (a != 0 && res / a != b)
	{
		res = 0;
	}
	return (res);
}

int	division(int a, int b)
{
	return (a / b);
}

int	modulo(int a, int b)
{
	return (a % b);
}

int	addition(int a, int b)
{
	int	res;

	res = a + b;
	if ((a < 0) == (b < 0) && (res < 0) != (a < 0))
	{
		res = 0;
	}
	return (res);
}

int	substraction(int a, int b)
{
	int	res;

	res = a - b;
	return (res);
}
