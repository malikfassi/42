/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thunerbl <theohunerblaes@me.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/27 17:47:03 by thunerbl          #+#    #+#             */
/*   Updated: 2013/07/28 13:41:31 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_display_grid(int	**grid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
	write(1,"\n",1);
	i++;
	}	
}
