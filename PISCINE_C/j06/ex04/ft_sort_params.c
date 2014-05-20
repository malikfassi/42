/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/24 08:23:31 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/24 13:44:34 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	b;
	int	ok;

	ok = 0;
	b = 0;
	while (*s1 != '\0' && *s2 != '\0' && b == 0)
	{
		b = *s1 - *s2;
		if (b == 0)
		{
			s1++;
			s2++;
		}
	}
	b = *s1 - *s2;
	return (b);
}

void	str_swap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	bubble_str_list_sort(char **array, int length)
{
	int	swapped;
	int	i;

	i = 1;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 2;
		while (i < length)
		{
			if (ft_strcmp(array[i - 1], array[i]) > 0)
			{
				str_swap(&array[i - 1], &array[i]);
				swapped = 1;
			}
			i++;
		}
		length--;
	}
}


int	main(int argc, char **argv)
{
	int	index;
	char	*arg;

	bubble_str_list_sort(argv, argc);
	index = 1;
	while (index < argc)
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
