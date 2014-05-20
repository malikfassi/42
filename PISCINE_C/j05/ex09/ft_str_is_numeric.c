/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 04:19:41 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/23 23:30:10 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (! *str)
		return (1);
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			count++;
		i++;
	}
	if (str[count] == '\0')
		return (1);
	else
		return (0);
}
