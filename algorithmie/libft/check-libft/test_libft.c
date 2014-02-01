/*autor : qperez
** HC test : mfontain
**
** Any segfault ? Probably caused by a NULL test. ex : ft_memset(NULL, 0, 0);
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "../libft/libft.h" /* compile with -I./ */
#define D_ERROR { printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__); return (0); }

#define D_TEST  50
#define RANDT   512
#define LONG    10000

typedef struct  s_test
{
	const char *name;
	int                     (*funct)(void);
	bool            set;
}                               t_test;

void    uf_free_tab(void **tab)
{
	unsigned int    i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i = i + 1;
	}
	free(tab);
}
/*
int             uf_test_strsplit(void)
{
	char    **ret;

	ret = ft_strsplit("", '*');
	if (ret[0] != NULL)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	uf_free_tab((void **)ret);
	ret = ft_strsplit("hello", '*');
	if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	uf_free_tab((void **)ret);
	ret = ft_strsplit("*hello", '*');
	if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	uf_free_tab((void **)ret);
	ret = ft_strsplit("*hello*", '*');
	if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	uf_free_tab((void **)ret);
	ret = ft_strsplit("*hel*lo*", '*');
	if (ret[2] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	uf_free_tab((void **)ret);
	ret = ft_strsplit("*hel*lo*f", '*');
	if (ret[3] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0 &&
			strcmp(ret[2], "f") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	uf_free_tab((void **)ret);
	ret = ft_strsplit("g*hel*lo*f", '*');
	if (ret[4] != NULL && strcmp(ret[0], "g") != 0 && strcmp(ret[1], "hel") != 0 &&
			strcmp(ret[2], "lo") != 0 && strcmp(ret[3], "f") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	uf_free_tab((void **)ret);
	return (1);
}

int             uf_test_strjoin(void)
{
	char    *ret;

	ret = ft_strjoin("Hello ", "boys");
	if (strcmp(ret, "Hello boys") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	return (1);
}

int             uf_test_strsub(void)
{
	char    *ret;
	char    str[] = "*Hello*";

	ret = ft_strsub(str, 1, 5);
	if (strcmp(ret, "Hello") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	return (1);
}
*/
void    uf_striteri_callback(unsigned int i, char *s)
{
	*s = *s + i;
}

void    uf_striter_callback(char *s)
{
	*s = *s + 1;
}

char    uf_strmap_callback(char s)
{
	return (s + 1);
}

char    uf_strmapi_callback(unsigned int i, char s)
{
	return (s + i);
}
/*
int             uf_test_itoa(void)
{
	char    *ret;
	if (strcmp(ret = ft_itoa(0), "0") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(-123), "-123") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(123), "123") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(-2147483648), "-2147483648") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(2147483647), "2147483647") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	return (1);
}

int             uf_test_strnequ(void)
{
	if (ft_strnequ("abc", "abc", 2) != 1)
		D_ERROR
			if (ft_strnequ("cba", "abc", 2) != 0)
				D_ERROR
					if (ft_strnequ("abc", "cba", 2) != 0)
						D_ERROR
							if (ft_strnequ("", "", 3) != 1)
								D_ERROR
									return (1);
}

int             uf_test_strequ(void)
{
	if (ft_strequ("abc", "abc") != 1)
		D_ERROR
			if (ft_strequ("cba", "abc") != 0)
				D_ERROR
					if (ft_strequ("abc", "cba") != 0)
						D_ERROR
							if (ft_strequ("", "") != 1)
								D_ERROR
									return (1);
}

int             uf_test_strmapi(void)
{
	char    str[] = "Hello";
	char    *ret;

	ret = ft_strmapi(str, uf_strmapi_callback);
	if (strcmp(ret, "Hfnos") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	return (1);
}

int             uf_test_strmap(void)
{
	char    str[] = "Hello";
	char    *ret;

	ret = ft_strmap(str, uf_strmap_callback);
	if (strcmp(ret, "Ifmmp") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	return (1);
}


int             uf_test_striteri(void)
{
	char    str[] = "Hello";

	ft_striteri(str, uf_striteri_callback);
	if (strcmp(str, "Hfnos") != 0)
		D_ERROR
			return (1);
}

int             uf_test_striter(void)
{
	char    str[] = "Hello";

	ft_striter(str, uf_striter_callback);
	if (strcmp(str, "Ifmmp") != 0)
		D_ERROR
			return (1);
}

int             uf_test_strclr(void)
{
	int             i;
	char    str[] = "Hello";

	i = 0;
	ft_strclr(str);
	while (i < 6)
	{
		if (str[i] != '\0')
			D_ERROR
				i = i + 1;
	}
	return (1);
}

int             uf_test_strdel(void)
{
	char    *ret;

	ret = ft_strnew(4);
	ft_strdel(&ret);
	if (ret != NULL)
		D_ERROR
			ret = ft_strnew(0);
	if (ret != NULL)
		D_ERROR
			return (1);
}

int             uf_test_strnew(void)
{
	char    *ret;
	int             i;

	i = 0;
	ret = ft_strnew(4);
	if (ret != NULL)
	{
		while (i < 5)
		{
			if (ret[i] != '\0')
				D_ERROR
					i = i + 1;
		}
	}
	return (1);
}

int             uf_test_memalloc_and_del(void)
{
	void    *ret;

	ret = ft_memalloc(4);
	ft_memdel(&ret);
	if (ret != NULL)
		D_ERROR
			return (1);
}

int             uf_test_tolower(void)
{
	int     i;

	i = 0;
	while (i < 255)
	{
		if (tolower(i) != ft_tolower(i))
			D_ERROR
				i = i + 1;
	}
	return (1);
}


int             uf_test_toupper(void)
{
	int     i;

	i = 0;
	while (i < 255)
	{
		if (toupper(i) != ft_toupper(i))
			D_ERROR
				i = i + 1;
	}
	return (1);
}

int             uf_test_isprint(void)
{
	int     i;

	i = 0;
	while (i < 255)
	{
		if (isprint(i) != ft_isprint(i))
			D_ERROR
				i = i + 1;
	}
	return (1);
}

int             uf_test_isascii(void)
{
	int     i;

	i = 0;
	while (i < 255)
	{
		if (isascii(i) != ft_isascii(i))
			D_ERROR
				i = i + 1;
	}
	return (1);
}

int             uf_test_isalnum(void)
{
	int     i;

	i = 0;
	while (i < 255)
	{
		if (isalnum(i) != ft_isalnum(i))
			D_ERROR
				i = i + 1;
	}
	return (1);
}

int             uf_test_isdigit(void)
{
	int     i;

	i = 0;
	while (i < 255)
	{
		if (isdigit(i) != ft_isdigit(i))
			D_ERROR
				i = i + 1;
	}
	return (1);
}

int             uf_test_isalpha(void)
{
	int     i;

	i = 0;
	while (i < 255)
	{
		if (isalpha(i) != ft_isalpha(i))
			D_ERROR
				i = i + 1;
	}
	return (1);
}

int             uf_test_atoi(void)
{
	if (atoi("\n -123") != ft_atoi("\n -123"))
		D_ERROR
			if (atoi("\v\t\r\f-123") != ft_atoi("\v\t\r\f-123"))
				D_ERROR
					if (atoi("12-3") != ft_atoi("12-3"))
						D_ERROR
							if (atoi("-+123") != ft_atoi("-+123"))
								D_ERROR
									if (atoi("a123") != ft_atoi("a123"))
										D_ERROR
											if (atoi("123a") != ft_atoi("123a"))
												D_ERROR
													if (atoi("123") != ft_atoi("123"))
														D_ERROR
															if (atoi("-123") != ft_atoi("-123"))
																D_ERROR
																	if (atoi("+123") != ft_atoi("+123"))
																		D_ERROR
																			if (atoi(" 123") != ft_atoi(" 123"))
																				D_ERROR
																					if (atoi(" - 123") != ft_atoi(" - 123"))
																						D_ERROR
																							if (atoi("\t -123") != ft_atoi("\t-123"))
																								D_ERROR
																									if (atoi("-2147483648") != ft_atoi("-2147483648"))
																										D_ERROR
																											if (atoi("2147483647") != ft_atoi("2147483647"))
																												D_ERROR
																													return (1);
}

int             uf_test_strncmp(void)
{
	if (strncmp("abc", "abc", 2) != ft_strncmp("abc", "abc", 2))
		D_ERROR
			if (strncmp("cba", "abc", 2) != ft_strncmp("cba", "abc", 2))
				D_ERROR
					if (strncmp("abc", "cba", 2) != ft_strncmp("abc", "cba", 2))
						D_ERROR
							if (strncmp("", "", 3) != ft_strncmp("", "", 3))
								D_ERROR
									return (1);
}

int             uf_test_strcmp(void)
{
	if (strcmp("abc", "abc") != ft_strcmp("abc", "abc"))
		D_ERROR
			if (strcmp("cba", "abc") != ft_strcmp("cba", "abc"))
				D_ERROR
					if (strcmp("abc", "cba") != ft_strcmp("abc", "cba"))
						D_ERROR
							if (strcmp("", "") != ft_strcmp("", ""))
								D_ERROR
									return (1);
}

int             uf_test_strnstr(void)
{
	char    *str = "Hello les genw";

	if (strnstr(str, "Hello", 3) != ft_strnstr(str, "Hello", 3))
		D_ERROR
			if (strnstr(str, "les", 1) != ft_strnstr(str, "les", 1))
				D_ERROR
					if (strnstr(str, "gen", 2) != ft_strnstr(str, "gen", 2))
						D_ERROR
							if (strnstr(str, "w", 0) != ft_strnstr(str, "w", 0))
								D_ERROR
									if (strnstr(str, "", 3) != ft_strnstr(str, "", 3))
										D_ERROR
											return (1);
}

int             uf_test_strstr(void)
{
	char    *str = "Hello les genw";

	if (strstr(str, "Hello") != ft_strstr(str, "Hello"))
		D_ERROR
			if (strstr(str, "les") != ft_strstr(str, "les"))
				D_ERROR
					if (strstr(str, "gen") != ft_strstr(str, "gen"))
						D_ERROR
							if (strstr(str, "w") != ft_strstr(str, "w"))
								D_ERROR
									if (strstr(str, "") != ft_strstr(str, ""))
										D_ERROR
											return (1);
}

int     uf_test_strrchr(void)
{
	char    str[] = "Hello je tesx";

	if (strrchr(str, 'H') != ft_strrchr(str, 'H'))
		D_ERROR
			if (strrchr(str, 'j') != ft_strrchr(str, 'j'))
				D_ERROR
					if (strrchr(str, 'x') != ft_strrchr(str, 'x'))
						D_ERROR
							if (strrchr(str, 0) != ft_strrchr(str, 0))
								D_ERROR
									return (1);
}

int     uf_test_strchr(void)
{
	char    str[] = "Hello je tesx";

	if (strchr(str, 'H') != ft_strchr(str, 'H'))
		D_ERROR
			if (strchr(str, 'j') != ft_strchr(str, 'j'))
				D_ERROR
					if (strchr(str, 'x') != ft_strchr(str, 'x'))
						D_ERROR
							if (strchr(str, 'y') != ft_strchr(str, 'y'))
								D_ERROR
									if (strchr(str, 0) != ft_strchr(str, 0))
										D_ERROR
											return (1);
}

int     uf_test_strlcat(void)
{
	char    dest[50] = {0};
	char    dest2[50] = {0};


	if (strlcat(dest, "Hello ", 4) != ft_strlcat(dest2, "Hello ", 4))
		D_ERROR
			memset(dest, 0, sizeof(dest));
	memset(dest2, 0, sizeof(dest));
	strlcat(dest, "Hello ", 4);
	ft_strlcat(dest2, "Hello ", 4);
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			strlcat(dest, "Hello ", 1);
	ft_strlcat(dest2, "Hello ", 1);
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			return (1);
}

int     uf_test_strncat(void)
{
	char    dest[50] = {0};
	char    dest2[50] = {0};

	if (strncat(dest, "hello ", 2) != ft_strncat(dest, "hello ", 2))
		D_ERROR
			memset(dest, 0, sizeof(dest));
	strncat(dest, "Hello ", 4);
	ft_strncat(dest2, "Hello ", 4);
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			strncat(dest, "Hello ", 2);
	ft_strncat(dest2, "Hello ", 2);
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			return (1);
}

int     uf_test_strcat(void)
{
	char    dest[50] = {0};
	char    dest2[50] = {0};

	if (strcat(dest, "hello ") != ft_strcat(dest, "hello "))
		D_ERROR
			memset(dest, 0, sizeof(dest));
	strcat(dest, "Hello ");
	ft_strcat(dest2, "Hello ");
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			strcat(dest, "Hello ");
	ft_strcat(dest2, "Hello ");
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			return (1);
}

int     uf_test_strncpy(void)
{
	int     i;
	char    dest[50] = {0};
	char    dest2[50] = {0};

	i = 0;
	if (strncpy(dest, "Hello foo", 6) != ft_strncpy(dest, "Hello foo", 6))
		D_ERROR
			strncpy(dest, "Hello foo", 6);
	ft_strncpy(dest2, "Hello foo", 6);
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			strncpy(dest, "Hello", 2);
	ft_strncpy(dest2, "Hello", 2);
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			dest[19] = 'a';
	ft_strncpy(dest, "", 40);
	if (dest[19] != '\0')
		D_ERROR
			dest2[19] = 'a';
	strncpy(dest2, "", 40);
	if (dest2[19] != '\0')
		D_ERROR
			memset(dest, '\0', sizeof(dest));
	memset(dest2, '\0', sizeof(dest));
	strncpy(dest, "abc", 3);
	strncpy(dest, "123", 1);
	if (dest[1] != 'b' && dest[2] != 'c')
		D_ERROR
			ft_strncpy(dest2, "abc", 3);
	ft_strncpy(dest2, "123", 1);
	if (dest[1] != 'b' && dest[2] != 'c')
		D_ERROR
			return (1);
}

int     uf_test_strcpy(void)
{
	char    dest[50] = {0};
	char    dest2[50] = {0};

	if (strcpy(dest, "Hello foo") != ft_strcpy(dest, "Hello foo"))
		D_ERROR
			strcpy(dest, "Hello foo");
	ft_strcpy(dest2, "Hello foo");
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			strcpy(dest, "Hello");
	ft_strcpy(dest2, "Hello");
	if (strcmp(dest, dest2) != 0)
		D_ERROR
			return (1);
}

int     uf_test_strdup(void)
{
	char    *ret1;
	char    *ret2;

	ret1 = strdup("");
	ret2 = ft_strdup("");
	if (strcmp(ret1, ret2) != 0)
		D_ERROR
			free(ret1);
	free(ret2);
	ret1 = strdup("hello");
	ret2 = ft_strdup("hello");
	if (strcmp(ret1, ret2) != 0)
		D_ERROR
			free(ret1);
	free(ret2);
	return (1);
}

int     uf_test_strlen(void)
{
	if (strlen("") != ft_strlen(""))
		D_ERROR
			if (strlen("abc") != ft_strlen("abc"))
				D_ERROR
					if (strlen("a") != ft_strlen("a"))
						D_ERROR
							return (1);
}

int     uf_test_memmove(void)
{
	char    str[] = "memmove can be very useful......";
	char    str2[] = "memmove can be very useful......";
	char    str3[] = "memmove can be very useful......";
	char    str4[] = "memmove can be very useful......";

	if (strcmp(memmove(str + 10, str + 5, 10), ft_memmove(str2 + 10, str2 + 5, 10)) != 0)
		D_ERROR
			if (strcmp(memmove(str3 + 5, str3 + 10, 10), ft_memmove(str4 + 5, str4 + 10, 10)) != 0)
				D_ERROR
					return (1);
}

int     uf_test_memchr(void)
{
	char    tab[11] = "Hello boys\0";
	char    tab2[11] = "Hello boys\0";
	char    cpy[6] = "olleh\0";

	if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
		D_ERROR
			memcpy(tab, "Hello", 5);
	ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
	memccpy(tab, cpy, 'o', sizeof(cpy));
	if (memchr(tab, 'y', sizeof(tab)) != ft_memchr(tab, 'y', sizeof(tab)))
		D_ERROR
			ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
	memccpy(tab + 1, cpy, 7, sizeof(cpy));
	if (memchr(tab, 'h', sizeof(tab)) != ft_memchr(tab, 'h', sizeof(tab)))
		D_ERROR
			return (1);
}

int     uf_test_memcmp(void)
{
	char    tab[11] = "Hello boys\0";
	char    tab2[11] = "Hello boys\0";
	char    cpy[6] = "olleh\0";

	if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
		D_ERROR
			memcpy(tab, "Hello", 5);
	ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
	memccpy(tab, cpy, 'o', sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != ft_memcmp(tab, tab2, sizeof(tab)))
		D_ERROR
			ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
	memccpy(tab + 1, cpy, 7, sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != ft_memcmp(tab, tab2, sizeof(tab)))
		D_ERROR
			return (1);
}
*/
int     uf_test_memccpy(void)
{
	char    tab[11] = "Hello boys\0";
	char    tab2[11] = "Hello boys\0";
	char    cpy[6] = "olleh\0";

	if (ft_memccpy(tab, cpy, 'o', sizeof(cpy)) != memccpy(tab, cpy, 'o', sizeof(cpy)))
		D_ERROR
			memcpy(tab, "Hello", 5);
	ft_memccpy(tab2, cpy, 'o', sizeof(cpy));
	memccpy(tab, cpy, 'o', sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != 0)
		D_ERROR
			ft_memccpy(tab2 + 1, cpy, 7, sizeof(cpy));
	memccpy(tab + 1, cpy, 7, sizeof(cpy));
	if (memcmp(tab, tab2, sizeof(tab)) != 0)
		D_ERROR
			return (1);
}

int     uf_test_memcpy(void)
{
	char            ctab[11], ctab2[11], ctab3[11];
	int             itab[11], itab2[11], itab3[11];
	unsigned long   ltab[11], ltab2[11], ltab3[11];
	int             i, j;
	size_t          k;
	void            *temp, *temp2, *temp3;

	printf("\033[33mHC test\033[0m : ");
	memcpy(NULL, NULL, 0);
	ft_memcpy(NULL, NULL, 0);
	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				itab[j] = rand();
				itab2[j] = 0; itab3[j] = 0;
				ltab[j] = (unsigned long)rand() * LONG;
				ltab2[j] = 0; ltab3[j] = 0;
				j++;
			}
			memcpy(ctab2, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp = ft_memcpy(ctab3, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			memcpy(itab2, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = ft_memcpy(itab3, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			memcpy(ltab2, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp3 = ft_memcpy(ltab3, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			if ((memcmp(itab2, itab3, sizeof(itab)) != 0 || (temp2 != itab3)))
				D_ERROR
					if (memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || temp != ctab3)
						D_ERROR
							if (memcmp(ltab2, ltab3, sizeof(ltab)) != 0 ||( temp3 != ltab3))
								D_ERROR
									++i;
		}
		++k;
	}
	return (1);
}

int     uf_test_memset(void)
{
	char            ctab[11], ctab2[11];
	int             itab[11], itab2[11];
	unsigned long   ltab[11], ltab2[11];
	size_t             i, j, k;
	void            *temp, *temp2;

	printf("\033[33mHC test\033[0m : ");
	memset(NULL, 0, 0);
	ft_memset(NULL, 0, 0);
	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				itab[j] = rand();
				ltab[j] = (unsigned long)rand() * LONG;
				j++;
			}
			memcpy(ctab2, ctab, sizeof(ctab));
			memcpy(itab2, itab, sizeof(itab));
			memcpy(ltab2, ltab, sizeof(ltab));
			temp = ft_memset(itab, i, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = memset(itab2, i, (k < sizeof(itab)) ? k : sizeof(itab));
			if (memcmp(itab, itab2, sizeof(itab)) != 0 || temp != itab || temp2 != itab2)
				D_ERROR
					temp = ft_memset(ctab, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp2 = memset(ctab2, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			if (memcmp(ctab, ctab2, sizeof(ctab)) != 0 || temp != ctab || temp2 != ctab2)
				D_ERROR
					temp = ft_memset(ltab, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp2 = memset(ltab2, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			if (memcmp(ltab, ltab2, sizeof(ltab)) != 0 || temp != ltab || temp2 != ltab2)
				D_ERROR
					++i;
		}
		++k;
	}
	return (1);
}

int     uf_test_bzero(void)
{
	char            ctab[11], ctab2[11];
	int             itab[11], itab2[11];
	unsigned long   ltab[11], ltab2[11];
	size_t          i, j;

	printf("\033[33mHC test\033[0m : ");
	i = 0;
	bzero(NULL, 0);
	ft_bzero(NULL, 0);
	while (i < 11)
	{
		j = 0;
		while (j < 11)
		{
			ctab[j] = (char)rand();
			itab[j] = rand();
			ltab[j] = (unsigned long)rand() * LONG;
			j++;
		}
		memcpy(ctab2, ctab, sizeof(ctab));
		memcpy(itab2, itab, sizeof(itab));
		memcpy(ltab2, ltab, sizeof(ltab));
		bzero(ctab2, i);
		ft_bzero(ctab, i);
		if (memcmp(ctab, ctab2, sizeof(ctab)) != 0)
			D_ERROR
				bzero(itab2, i);
		ft_bzero(itab, i);
		if (memcmp(itab, itab2, sizeof(itab)) != 0)
			D_ERROR
				bzero(ltab2, i);
		ft_bzero(ltab, i);
		if (memcmp(ltab, ltab2, sizeof(ltab)) != 0)
			D_ERROR
				++i;
	}
	return (1);
}

void    uf_add_test(t_test *test, const char *name, int (*funct)(void))
{
	static int      i = 0;

	test[i].name = name;
	test[i].funct = funct;
	test[i].set = true;
	i = i + 1;
}

int             main(int argc, const char **argv)
{
	int             i;
	t_test  test[D_TEST];

	srand(time(NULL));
	i = 0;
	memset(test, 0, D_TEST);
	uf_add_test(test, "memset", uf_test_memset);
	uf_add_test(test, "bzero", uf_test_bzero);
	uf_add_test(test, "memcpy", uf_test_memcpy);
	/*uf_add_test(test, "memccpy", uf_test_memccpy);
	  uf_add_test(test, "memmove", uf_test_memmove);
	  uf_add_test(test, "memchr", uf_test_memchr);
	  uf_add_test(test, "memcmp", uf_test_memcmp);
	  uf_add_test(test, "strlen", uf_test_strlen);
	  uf_add_test(test, "strdup", uf_test_strdup);
	  uf_add_test(test, "strcpy", uf_test_strcpy);
	  uf_add_test(test, "strncpy", uf_test_strncpy);
	  uf_add_test(test, "strcat", uf_test_strcat);
	  uf_add_test(test, "strncat", uf_test_strncat);
	  uf_add_test(test, "strlcat", uf_test_strlcat);
	  uf_add_test(test, "strchr", uf_test_strchr);
	  uf_add_test(test, "strrchr", uf_test_strrchr);
	  uf_add_test(test, "strstr", uf_test_strstr);
	  uf_add_test(test, "strnstr", uf_test_strnstr);
	  uf_add_test(test, "strcmp", uf_test_strcmp);
	  uf_add_test(test, "strncmp", uf_test_strncmp);
	  uf_add_test(test, "atoi", uf_test_atoi);
	  uf_add_test(test, "alpha", uf_test_isalpha);
	  uf_add_test(test, "digit", uf_test_isdigit);
	  uf_add_test(test, "alnum", uf_test_isalnum);
	  uf_add_test(test, "isascii", uf_test_isascii);
	  uf_add_test(test, "isprint", uf_test_isprint);
	  uf_add_test(test, "toupper", uf_test_toupper);
	  uf_add_test(test, "tolower", uf_test_tolower);
	  uf_add_test(test, "memalloc_del", uf_test_memalloc_and_del);
	  uf_add_test(test, "strnew", uf_test_strnew);
	  uf_add_test(test, "strdel", uf_test_strdel);
	  uf_add_test(test, "strclr", uf_test_strclr);
	  uf_add_test(test, "striter", uf_test_striter);
	  uf_add_test(test, "striteri", uf_test_striteri);
	  uf_add_test(test, "strmap", uf_test_strmap);
	  uf_add_test(test, "strmapi", uf_test_strmapi);
	  uf_add_test(test, "strequ", uf_test_strequ);
	  uf_add_test(test, "strnequ", uf_test_strnequ);
	  uf_add_test(test, "strsub", uf_test_strsub);
	  uf_add_test(test, "strjoin", uf_test_strjoin);
	  uf_add_test(test, "strplit", uf_test_strsplit);
	  uf_add_test(test, "itoa", uf_test_itoa);*/
	while (i < D_TEST && test[i].set == true)
	{
		printf("Test [%s] : ", test[i].name);
		if (test[i].funct() == 0)
			printf("\033[31mFAIL\033[0m\n");
		else
			printf("\033[32mOK\033[0m\n");
		i = i + 1;
	}
	(void)argc;
	(void)argv;
	return (0);
}
