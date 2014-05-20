/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/25 18:18:03 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/26 07:31:12 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_generic(void)
{
	char	*str;
	int	i;

	str = "Tut tut ; Tut tut\n";
	while (str[i] != '\0')
	{
		write(1,&str[i],1);
		i++;
	}
}
