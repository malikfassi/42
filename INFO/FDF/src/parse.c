/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 11:14:27 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/01/02 20:33:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <fcntl.h>
#include <libft.h>
#include <stdio.h>

/*
   while (get_next_line(fd, &line))
   {
   splitted_line = ft_strsplit(line, ' ');
   printf("==> %s\n", line);
   }
   if ((fd = open(argv[1], O_RDONLY)) == -1 )
   {
   strerror(errno);
   return (0);
   }
   */

int	get_charss_len(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

void	free_array(void ***array)
{
	int i;

	i = 0;
	while (array[i])
	{
		printf("avant boucle i = %i, je free %s\n", i, (char *)*(array[i]));
		free(*array[i]);
		array[i] = NULL;
		i++;
		printf("END\n");
	}
	printf("apres boucle\n");
	free(array);
	array = NULL;
}
