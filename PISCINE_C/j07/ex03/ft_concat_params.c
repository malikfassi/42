/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/25 05:04:05 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/25 23:19:02 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_length(char *str)
{
	int	i;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i-1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i] != '\0')
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strcat(char* dest, char *src)
{
	char	*res;

	res = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		if (! *src)
		{
			return (res);
		}
		dest++;
		src++;
	}
	*dest = '\0';
	return (res);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*params;
	int	index;
	int	total_length;
	int	param_length;
	
	index = 1;
	total_length = 0;
	while (index < argc)
	{
		param_length = get_length(argv[index]);
		total_length += param_length + 1;
		index++;
	}
	index = 1;
	params = malloc(sizeof(int) * (param_length + 1));
	while (index < argc)
	{
		ft_strcat(params, argv[index]);
		ft_strcat(params, "\n");
		index++;
	}
	ft_strcat(params,"\0");
	return(params);
}
