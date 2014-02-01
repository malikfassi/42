/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_arr_triple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 16:31:07 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/25 11:53:34 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <stdio.h>

int	len_arr_triple(char ***arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	print_arr_triple(char ***arr)
{
	ft_putstr_fd("[", 2);
	while (*arr)
	{
		print_arr(*arr);
		arr++;
		ft_putstr_fd(",", 2);
	}
	ft_putstr_fd("]", 2);
}
