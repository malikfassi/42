/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 02:25:05 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/23 23:28:57 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (('A' <=  str[i]) && (str[i] <= 'Z'))
		{
			str[i] = 'a' + (str[i] - 'A');
		}
		i++;
	}
	return (str);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (('a' <= str[i]) && (str[i] <= 'z'))
		{
			str[i] = 'A' + (str[i] - 'a');
		}
		i++;
	}
	return (str);
}

int	ft_char_is_alphanum(char c)
{
	if (('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z')
		|| ('0' <= c && c <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (ft_char_is_alphanum(str[index]))
		{
			ft_strupcase(str + index);
			while (ft_char_is_alphanum(str[index + 1]))
			{
				ft_strlowcase(str + index + 1);
				index++;
			}
		}
		if (str[index] != '\0')
			index++;
	}
	return (str);
}
