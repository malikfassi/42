/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:06:45 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/25 11:56:55 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	print_arr(char **arr)
{
	int		i;

	i = 0;
	ft_putstr_fd("(", 2);
	while (arr[i])
	{
		ft_putendl_fd(arr[i++], 2);
		ft_putstr_fd(";\n", 2);
	}
	ft_putstr_fd(")", 2);
}

void	ft_env()
{
	print_arr(ENVP);
}
