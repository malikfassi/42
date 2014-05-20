/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/26 01:16:45 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/26 07:38:06 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char	*str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (('a' <= str[index] && 'j' >= str[index])
			|| ('A' <= str[index] && 'J' >= str[index]))
		{
			str[index] += 16;
		}
		else if (('k' <= str[index] && 'z' >= str[index])
				|| ('K' <= str[index] && 'Z' >= str[index]))
		{
			str[index] = str[index] - 10;
		}
	index++;
	}
	return (str);
}
