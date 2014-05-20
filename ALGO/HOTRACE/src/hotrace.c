/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 01:01:20 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/15 21:12:51 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>
#include <tools.h>
#include <ft_data.h>
#include <stdio.h>

int	main(void)
{
	t_sizetree	*root;

	root = ft_init_data();
	ft_search_data(root);
	return (1);
}
