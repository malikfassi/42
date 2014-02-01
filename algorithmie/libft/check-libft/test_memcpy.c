/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:18:29 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/11/20 18:27:31 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_memcpy.c"
#include <stdio.h>

int main(void)
{
	const char src[6]="malik";
	char dst[9]= "bonj-our";
	printf("before : %s\n", dst);
	ft_memcpy(dst, src, 4);
	printf("after ft : %s\n", dst);
	return (0);
}
