/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 05:05:41 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/23 23:31:45 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (! *str)
		return (1);
	while (str[i] != '\0')
	{
		if (20 <= str[i] && str[i] <= 126)
			count++;
		i++;
	}
	if (str[count] == '\0')
		return (1);
	else
		return (0);
}
