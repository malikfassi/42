/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/22 16:29:55 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/22 16:54:57 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_eight_queens_puzzle(int i)
{
	if (i == 92)
		return (i);
	else
		return (find_eight_queens_puzzle(i + 1));
}

int	ft_eight_queens_puzzle(void)
{
	return (find_eight_queens_puzzle(1));
}
