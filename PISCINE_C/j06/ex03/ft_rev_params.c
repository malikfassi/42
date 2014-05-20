/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/24 08:13:08 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/24 13:40:37 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	index;
	char	*arg;

	index = argc - 1;
	while (index >= 1)
	{
		arg = argv[index];
		while (*arg != '\0')
		{
			ft_putchar(*arg);
			arg++;
		}
		ft_putchar('\n');
		index--;
	}
	return (0);
}
