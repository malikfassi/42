/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:00:49 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/29 19:32:34 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

int	find(char **arr, char *to_find, int pos)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], to_find) == 0 && i != pos)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i != 0 && str[i] == '-'))
			return (0);
		if (str[0] != '-' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_overflow(char *str)
{
	int		len;
	char	*maximum;
	char	*minimum;

	len = ft_strlen(str);
	minimum = "2147483648";
	maximum = "2147483647";
	str = (len == 11 && *str == '-') ? str + 1 : str;
	while (*str && len >= 10)
	{
		if (len == 10)
		{
			if (ft_strncmp(str, maximum, 1) > 0)
				return (1);
			maximum++;
		}
		else
		{
			if (ft_strncmp(str, minimum, 1) > 0)
				return (1);
			minimum++;
		}
		str++;
	}
	return (0);
}

int	param_ok(char **l_a)
{
	int	i;

	i = 0;
	while (l_a[i])
	{
		if (!ft_strisnum(l_a[i]))
			return (0);
		if (is_overflow(l_a[i]))
			return (0);
		if (find(l_a, l_a[i], i))
			return (0);
		i++;
	}
	return (1);
}
