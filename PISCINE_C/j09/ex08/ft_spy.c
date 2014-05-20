/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/26 08:28:04 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/26 09:08:40 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowercase(char *str);
int		ft_strcmp(char *str1, char *str2);
void	ft_putstr(char *str);
int		is_danger(char **argv, int i);

int	main(int argc,char **argv)
{
	int	i;
	int	found;

	i = 1;
	found = 0;
	while (i < argc && found == 0)
	{
		found = is_danger(argv, i);
		i++;
	}
	if (found)
	{
		ft_putstr("Alert!!!");
	}
	return (0);
}

int	is_danger(char **argv, int i)
{
	int	found;
	
	found = 0;
	ft_strlowercase(argv[i]);
	if (ft_strcmp(argv[i], "president" ) >= 0)
	{
		found = 1;
	}
	if (ft_strcmp(argv[i], "attentat" ) >= 0)
	{
		found = 1;
	}
	if (ft_strcmp(argv[i], "bauer" ) >= 0)
	{
		found = 1;
	}
	return (found);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	diff;

	str2--;
	while (*str1 == ' ')
	{
		str1++;
	}
	str1--;
	while (*(str1 +1) != '\0' && *(str2 +1) != '\0'
			&& *(str1+1) == *(str2+1))
	{
		str1++;
		str2++;
	}
	str1++;
	str2++;
	diff = (*str1 == '\0' || *str2 == '\0') ? *str1 - *str2 : -1;
	return (diff);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

char	*ft_strlowercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (('A' <= str[i]) && (str[i] <= 'Z'))
		{
			str[i] = 'a' + (str[i] - 'A');
		}
	i++;
	}
	return (str);
}
