/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 04:47:45 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/23 23:31:15 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (! *str)
		return (1);
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			count++;
		i++;
	}
	if (str[count] == '\0')
		return (1);
	else
		return (0);
}
