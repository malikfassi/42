/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:06:45 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/25 18:14:12 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_env.h>

void	print_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		ft_putendl(arr[i++]);
}

void	ft_env(char **envp, char **cmd)
{
	(void) cmd;
	print_arr(envp);
}
