/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:35:41 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/11/19 15:53:48 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_bzero.c"
#include <stdio.h>

int main(void)
{
	char test[6] = "malik";
	printf("%s\n", test);
	ft_bzero(test, 4);
	printf("%s", test);
	return (0);
}
