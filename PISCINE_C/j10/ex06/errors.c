/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/29 22:45:23 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/30 22:30:38 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "do_op.h"

int	check_op(char *str)
{
	if ((*str == '*' || *str == '/' || *str == '+'
		|| *str == '-' || *str == '%')
			&& *(str + 1) == '\0')
	{
		return (1);
	}
	return (0);
}

int	check_val(char *val)
{
	if (*val <= '9' && *val >= '0' )
	{
		return (1);
	}
	return (0);
}


int	errors(char *op, char *b)
{
	if (! (check_op(op)))
	{
		return (1);
	}
	else if (*op == '/' && to_int(b) == 0)
	{
		ft_print("Stop : division by zero\n");
		return (2);
	}
	else if (*op == '%' && to_int(b) == 0)
	{
		ft_print("Stop : modulo by zero\n");
		return (2);
	}
	return (0);
}
