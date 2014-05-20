/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 04:44:45 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/23 23:30:50 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	if (! *str)
		return (1);
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
			count++;
		i++;
	}
	if (str[count] == '\0')
		return (1);
	else
		return (0);
}
