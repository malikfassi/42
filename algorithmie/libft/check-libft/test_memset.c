/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:08:15 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/11/19 15:38:04 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_memset.c"
#include <stdio.h>

int	main(void)
{
	char test[6]="malik";
	printf("%s\n", test);
	ft_memset(test, 101, 5);
	printf("%s", test);
	return (0);	
}
