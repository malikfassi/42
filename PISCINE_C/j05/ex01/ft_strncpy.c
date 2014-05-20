/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 00:35:59 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/23 23:26:34 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	i = 0;
	while (i != n)
	{
		dest[i] = *src;
	i++;
	src++;
	}
	while (dest[i] != '\0')
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
