/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:12:19 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/11/22 13:00:09 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_memccpy.c"
#include <stdio.h>
#include <time.h>

#define D_ERROR { printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__); return (0);}
#define D_TEST 50


int     uf_test_memccpy(void)
{
	char    tab[11] = "Hello boys\0";
	char    tab2[11] = "Hello boys\0";
	char    cpy[6] = "olleh\0";

	if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
		D_ERROR
			memcpy(tab, "Hello", 5);
	ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
	memccpy(tab, cpy, 'o', sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != 0)
		D_ERROR
			ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
	memccpy(tab + 1, cpy, 7, sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != 0)
		D_ERROR
			return (1);
}

void    uf_add_test(t_test *test, const char *name, int (*funct)(void))
{
	static int      i = 0;

	test[i].name = name;
	test[i].funct = funct;
	test[i].set = true;
	i = i + 1;
}




int             main(int argc, const char **argv)
{
	int             i;
	t_test  test[D_TEST];

	srand(time(NULL));
	i = 0;
	memset(test, 0, D_TEST);
	uf_add_test(test, "memccpy", uf_test_memccpy);
	while (i < D_TEST && test[i].set == true)
	{
		printf("Test [%s] : ", test[i].name);
		if (test[i].funct() == 0)
			printf("\033[31mFAIL\033[0m\n");
		else
			printf("\033[32mOK\033[0m\n");
		i = i + 1;
	}
	(void)argc;
	(void)argv;
	return (0);
}
