/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/08 00:55:03 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/08/09 23:24:46 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

int	is_smaller_or_eq(char *a, char *b)
{
	return ( (ft_strlen(a)  < ft_strlen(b) || (ft_strlen(a) == ft_strlen(b) 
					&& b_strcmp(a, b) <= 0) ));
}


int	is_smaller(char *a, char *b)
{
	return ( (ft_strlen(a)  < ft_strlen(b) || (ft_strlen(a) == ft_strlen(b) 
					&& b_strcmp(a, b) < 0) ));
}


char *initialize(long long len, char first)
{
	char *element;

	if ((element =  malloc(sizeof(char) * (len))))
	{
		ft_memset(element, '\0', len);
		element[0] = first;
	}
	return (element);
}

/*
 ** val[0] = multiple;
 ** val[1] = i_multiple;
 ** val[2] = tmp_a;
 ** val[3] = result;
 ** counters[0] = i;
 ** counters[1] = j;
 ** counters[2] = size_a
 */


void	find_multiple(char **val, char *b)
{
	char *one[2];

	one[0] = val[4][1];
	one[1] = '\0';
	while (is_smaller(val[0], val[2]))
	{
		val[0] = addition(val[0], b, 0);
		val[1] = addition(val[1], one, 0);
	}
	val[1] = addition(val[1], one, 0);
	if (! is_smaller_or_eq(val[0], val[2]))
	{
		val[0] = subtraction(val[0], b);
		val[1] = subtraction(val[1], one);
	}
}

void	finish_div(char **val)
{
	val[3] = strcat(val[3], val[1]);
	val[1][0] = val[4][0];
	val[1][1] = '\0';
	val[2] = subtraction(val[2], val[0]);
}


void	initialize_val(char *a, long long size_a, char **val, int sign)
{
	val[4] = argv[1];
	val[5] = argv[2];
	val[0] = initialize(size_a + 1, 0);
	val[1] = initialize(size_a + 1, val[4][0]);
	val[2] = initialize(size_a + 1, *a);
	val[3] = (sign) ? initialize(size_a + 2, 0) : initialize(size_a + 1, 0);
	val[3][0] = (sign) ? val[5][3] : val[3][0];
}

void	initialize_counters(long long *counters, char *a)
{
	counters[0] = 1;
	counters[1] = 0;
	counters[2] = ft_strlen(a);
}

void	before_add_z(char *next, char *a, long long *counters, char **val)
{
	next[0] = a[counters[0]];
	val[2] = strcat(val[2], next);
	rmv_zero(val[2], 0);
	counters[1]++;
}

void	initialize_z_n(char **argv, char *next, char *zero)
{
	zero[0] = argv[1][0];
	zero[1] = '\0';
	next[1] ='\0';
}

void	free_data(char **val)
{
	free(val[0]);
	free(val[1]);
	free(val[2]);
}

char *division(char *a, char *b, int sign, char **argv)
{
	long long counters[3];
	char next[2];
	char *val[6];
	char zero[1];

	initialize_z_n(argv, next, zero);
	initialize_counters(counters, a);
	initialize_val(a, counters[2], val, sign);
	while (counters[0] < counters[2])
	{
		val[0] = ft_strcpy(val[0], b);
		while (is_smaller(val[2], b) && counters[0] < counters[2])
		{
			before_add_z(next, a, counters, val);
			val[3] = (counters[1] > 1) ? strcat(val[3], zero) : val[3];
			counters[0]++;
		}
		counters[1] = 0;
		find_multiple(val, b);
		finish_div(val);
	}
	rmv_zero(val[3], 0);
	free_data(val);
	return (val[3]);
}

char *modulo(char *a, char *b, int sign, char **argv)
{
	long long counters[3];
	char next[2];
	char *val[6];
	char zero[1];

	initialize_z_n(argv, next, zero);
	initialize_counters(counters, a);
	initialize_val(a, counters[2], val, sign);
	while (counters[0] < counters[2])
	{
		val[0] = ft_strcpy(val[0], b);
		while (is_smaller(val[2], b) && counters[0] < counters[2])
		{
			before_add_z(next, a, counters, val);
			val[3] = (counters[1] > 1) ? strcat(val[3], zero) : val[3];
			counters[0]++;
		}
		counters[1] = 0;
		find_multiple(val, b);
		finish_div(val);
	}
	rmv_zero(val[3], 0);
	return (tmp_a);
}

/*
   char *basic_division(char *a, char* b)
   {
   char *res;
   char *tmp_a;
   int res_size;
   tmp_a = malloc(sizeof(char) * (ft_strlen(a) + 1));

   tmp_a = ft_strcpy(tmp_a, a);
   res_size = (ft_strlen(a)  < ft_strlen(b) || (ft_strlen(a) == ft_strlen(b) && 
   ft_strcmp(a, b) >= 0)) ? 1 : (ft_strlen(a) - ft_strlen(b) + 20);
   res = malloc(sizeof(char) * res_size);
   res[0] = '0';
   while (ft_strlen(tmp_a) > ft_strlen(b) || (ft_strlen(tmp_a) == ft_strlen(b) 
   && ft_strcmp(tmp_a, b) >= 0))
   {
res = addition(res, "1", 0);
tmp_a = subtraction(tmp_a, b);
}
free(tmp_a);
return (res);
}
*/

