/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_places.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/25 19:05:34 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/26 07:33:37 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	print_beginning(int hour)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (((hour < 10 && hour > 0) || (hour < 23 && hour > 12)) && hour != 22 )
	{
		printf("0");
	}
	if (hour > 12)
	{
		printf("%d", hour - 12);
	}
	else if (hour == 0)
	{
		printf("12");
	}
	else
	{
		printf("%d", hour);
	}
}

void	print_am(int hour)
{
	if ((hour < 10 && hour >= 0)
		|| (hour < 23 && hour > 12))
	{
		printf(".00 A.M. AND 0%d.00 A.M.", hour);
	}
	else
	{
		printf(".00 A.M. AND %d.00 A.M.", hour);
	}
}


void	print_pm(int hour)
{
	if ((hour < 10 && hour >= 0)
		|| (hour < 23 && hour > 12))
	{
		printf(".00 P.M. AND 0%d.00 P.M.", hour);
	}
	else
	{
		printf(".00 P.M. AND %d.00 P.M.", hour);
	}
}



void	ft_takes_place(int hour)
{
	print_beginning(hour);
	if(hour < 11)
	{
		print_am(hour + 1);
	}
	else if(hour == 11)
	{
		printf(".00 A.M. AND 12.00 P.M.");
	}
		else if (hour < 23)
	{
		print_pm(hour + 11);
	}
	else if(hour == 11)
	{
		printf(".00 A.M. AND 12.00 P.M.");
	}
	else
	{
		printf(".00 P.M. AND 12.00 A.M.");
	}
	printf("\n");
}
