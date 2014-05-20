/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 03:57:28 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/23 23:29:23 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (1);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (('a' <= str[i] && str[i] <= 'z')
			|| ('A' <= str[i] && str[i] <= 'Z'))
			count++;
		i++;
	}
	if (str[count] == '\0')
		return (1);
	else
		return (0);
}
