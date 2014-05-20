/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 00:44:23 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/23 23:26:10 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_if_same(char *str, char *to_find, int i)
{
	int	j;
	int	ok;

	j = 1;
	ok = 1;
	while (to_find[j] != '\0' && ok)
	{
		if (str[i + j] != to_find[j])
		{
			ok = 0;
		}
		j++;
	}
	return (ok);
}


char	*ft_strstr(char	*str, char *to_find)
{
	int	i;
	int	ok;
	int	begin;

	i = 0;
	ok = 1;
	begin = 0;

	if (! *to_find)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == *to_find)
			begin = 1;
		if (begin)
		{
			ok = check_if_same(str, to_find, i);
			if (ok)
				return (str + i);
		}
			ok = 1;
			begin = 0;
			i++;
	}
		return (NULL);
}
