/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/01 07:57:44 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/01 19:50:17 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_numeric(char *str, int offset)
{
	int	i;
	int	count;

	i = offset;
	count = offset;
	if (! *str)
		return (1);
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			count++;
		i++;
	}
	if (count == i)
	{
		return (1);
	}
	return (0);
}
