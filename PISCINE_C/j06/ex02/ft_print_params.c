/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/24 07:38:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/24 13:39:48 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	index;
	char	*arg;

	index = 1;
	whilei (index < argc)
	{
		arg = argv[index];
		while (*arg != '\0')
		{
			ft_putchar(*arg);
			arg++;
		}
		ft_putchar('\n');
		index++;
	}
	return (0);
}
