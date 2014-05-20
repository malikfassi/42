/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfourcad <fourcade.mathieu@gmail.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/03 16:17:50 by mfourcad          #+#    #+#             */
/*   Updated: 2013/08/04 23:35:12 by kmesas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 4096

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(48 + n);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	lenght;
	int	i;

	lenght = ft_strlen(dest);
	i = 0;
	while(src[i] != '\0')
	{
		dest[lenght + i] = src[i];
		i++;
	}
	dest[lenght + i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

char	*table(int *temp, int x_line, int y_line)
{
	char	*tab;

	*temp = (x_line + 1) * y_line - 1;
	tab = "o-o|o-o/*\\*\\*/ABABCBCABCBABCABCBCBA";
	return (tab);
}

int		ft_colle(char *buffer, int x_line, int	y_line)
{
	int		temp;
	char	*tab;

	tab = table(&temp, x_line, y_line);
	if (buffer[temp - 1] == tab[6])
	{
		return (0);
	}
	else if (buffer[temp - 1] == tab[13])
	{
		return (7);
	}
	else if (buffer[temp - 1] == tab[20] && buffer[temp - x_line] == tab[18])
	{
		return (14);
	}
	else if (buffer[temp - 1] == tab[27] && buffer[temp - x_line] == tab[25])
	{
		return (21);
	}
	else if (buffer[temp - 1] == tab[34] && buffer[temp - x_line] == tab[32])
	{
		return (28);
	}
	return (-1);
}

char	*ft_name(int offset)
{
	if (offset == 0)
	{
		return ("colle-00");
	}
	else if (offset == 7)
	{
		return ("colle-01");
	}
	else if (offset == 14)
	{
		return ("colle-02");
	}
	else if (offset == 21)
	{
		return ("colle-03");
	}
	else if (offset == 28)
	{
		return ("colle-04");
	}
	return ("Aucune colle\n");
}

char	*ft_check(char *buffer, int x_line, int y_line)
{
	int		check;
	int		temp;
	int		i;
	int		j;
	int		offset;
	char	*tab;

	i = 0;
	check = 0;
	tab = table(&temp, x_line, y_line);
	temp = ((x_line + 1) * y_line) - 1;
	offset = ft_colle(buffer, x_line, y_line);
	if ((buffer[0] == tab[0] || buffer[0] == tab[7] || buffer[0] == tab[14]) && (offset != -1 || (x_line == 1 && y_line == 1)))
	{
		check = 1;
		if (x_line == 1 || y_line == 1)
		{
			if (buffer[0] == tab[0])
			{
				return ("colle-00");
			}
			else if (buffer[0] == tab[7])
			{
				return ("colle-01");
			}
			else if (buffer[0] == tab[14])
			{
				if (buffer[temp - x_line] == tab[18] && y_line > 1)
				{
					return ("colle-02 and colle-04");
				}
				else if (buffer[temp - x_line] == tab[25] && y_line > 1)
				{
					return ("colle-03");
				}
				else if (buffer[temp - 1] == tab[23] && x_line > 1)
				{
					return ("colle-03 and colle-04");
				}
				else if (buffer[temp - 1] == tab[16] && x_line > 1)
				{
					return ("colle-02");
				}
				else if (x_line == 1 && y_line == 1)
				{
					return ("colle-02 ; colle-03 and colle-04");
				}
			}
			return ("Aucune\n");
		}
		while (buffer[i] != '\n' && check == 1)
		{
			i++;
			if (i > 0 && i < x_line && buffer[i] == tab[1 + offset] && x_line > 2)
			{
				check = 1;
			}
			else if (buffer[x_line - 1] == tab[2 + offset])
			{
				check = 1;
			}
			else
			{
				check = 0;
			}
		}
		i = 1;
		while (i < x_line - 1 && check == 1 && buffer[temp - 1] == tab[6 + offset] && buffer[temp - x_line] == tab[4 + offset] && x_line > 2)
		{
			i++;
			if (buffer[temp - i] == tab[5 + offset])
			{
				check = 1;
			}
			else
			{
				check = 0;
			}
		}
		j = x_line + 1;
		i = j;
		while (i < (temp - x_line) && check == 1 && buffer[x_line + 1] == tab[3 + offset] && x_line > 2)
		{
			i++;
			if (buffer[j + x_line - 1]  == tab[3 + offset] && buffer[j + x_line + 1] == tab[3 + offset])
			{
				check = 1;
			}
			else if (buffer[i] == ' ')
			{
				check = 1;
			}
			else if (buffer[i] == buffer[j + x_line + 2] && buffer[i] == '\n')
			{
				j += x_line;
			}
			else
			{
				check = 0;
			}
		}
	}
	if (check == 1)
	{
		return (ft_name(offset));
	}
	return ("Aucune\n");
}

void	*ft_realloc(void *old, void *add)
{
	void	*new;
	int		lenght;

	lenght = ft_strlen(old) + ft_strlen(add) + 1;
	if ((new = malloc((lenght + 1) * sizeof(*new))))
	{
		ft_strcpy(new, old);
		ft_strcat(new, add);
	}
	free(old);
	return (new);
}

int		main(int argc, char **argv)
{
	int		i;
	char	buf[BUF_SIZE + 1];
	char	*buffer;
	int		x_line;
	int		y_line;
	int		ret;
	int		tmp;

	argv = argv;
	i = 0;
	y_line = 0;
	x_line = 0;
	tmp = 0;
	if (argc == 1)
	{
		ret = read(0, buf, BUF_SIZE);
		buf[ret] = '\0';
		buffer = malloc((ret + 1) * sizeof(*buffer));
		ft_strcpy(buffer, buf);
		while ((ret = read(0, buf, BUF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			buffer = ft_realloc(buffer, buf);
		}
		while (buffer[i] != '\0')
		{
			while (buffer[i] != '\n' && buffer[i] != '\0')
			{
				i++;
				tmp++;
			}
			if (x_line < tmp)
			{
				x_line = tmp;
			}
			tmp = 0;
			i++;
			y_line++;
		}
		ft_putchar('[');
		ft_putstr(ft_check(buffer, x_line, y_line));
		ft_putstr("] [");
		ft_putnbr(x_line);
		ft_putstr("] [");
		ft_putnbr(y_line);
		ft_putstr("]\n");
	}
	else
	{
		ft_putstr("Error\n");
	}
	return (0);
}

