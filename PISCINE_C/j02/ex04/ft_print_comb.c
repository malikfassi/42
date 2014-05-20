/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/18 13:37:36 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/18 21:45:43 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void ft_putchar(char c);

void ft_print_comb()
{
	char	combi[3];

	combi[0]='0';
	combi[1]='1';
	combi[2]='2';
	while(combi[0] <= '7')
	{
		while(combi[1] <= '8')
		{
			while(combi[2] <= '9')
			{
				if(combi[0] < combi[1] && combi[1] < combi[2])
				{
					ft_putchar(combi[0]);
					ft_putchar(combi[1]);
					ft_putchar(combi[2]);
					if(combi[0] != '7')
					{
						ft_putchar(",");
						ft_putchar(" ");
					}
				}
			combi[2]++;
			}
		combi[2]=0;
		combi[1]++;
		}
		combi[1]=0;
		combi[0]++;
	}
}
