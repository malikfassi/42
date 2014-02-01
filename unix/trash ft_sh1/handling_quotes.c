static int  is_quote(char c)
{
	return (c == 34 || c == 39);
}

static int      get_nbwords(char *str, char c)
{
	int     nb_words;
	int     i;
	char    quotes;

	i = 0;
	nb_words = 0;
	while (str && *(str + i))
	{
		while (*(str + i) && *(str + i) == c)
			i++;
		if (is_quote(*(str + i)) && *(str + i - 1) != c)
		{
			nb_words++;
			quotes = *(str + i);
			while (*(str + i) != quotes && *(str + i + 1) != c)
			{
				i++;
			}
		}
		i -= (is_quote(*(str + i))) ? 1 : 0;
		nb_words += (*(str + i)) ? 1 : 0;
		while (*(str + i) && *(str + i) != c)
			i++;



		quotes = 0;
		if (*(str + i) && is_quote(*(str + i)))
			quotes = (*(str + i++) == 34) ? 34 : 39;
		printf("quotes = %c\n et str[i] = %c", quotes, *(str + i));
		if (quotes)
		{
			while (*(str + i) && *(str + i) != quotes)
				i++;
			i = (*(str + i) == quotes) ? i + 1 : i;
			nb_words++;
		}
		else
		{
		}
	}
	return (nb_words);
}

static void check_quotes(char *str, int *tab, char **ptr)
{
	char    quotes;

	quotes = 0;
	if (*(str + tab[1]) && (*(str + tab[1]) == 34 || *(str + tab[1]) == 39))
		quotes = (*(str + tab[1]++) == 34) ? 34 : 39;
	if (quotes)
	{
		printf("il y a quotes\n");
		while (*(str + tab[2] + tab[2]) && *(str + tab[1] + tab[2]) != quotes)
			tab[2]++;
		ptr[tab[0]] = ft_strsub(str, tab[1], tab[2] - 1);
		tab[1] += tab[2];
		tab[2] = 0;
		tab[0]++;
	}
}


char    **args_split(char *s)
{
	char    **ptr;
	int     tab[3];

	tab[0] = 0;         //tab[0] = i;
	tab[1] = 0;         //tab[1] = start;
	tab[2] = 0;         //tab[2] = end;
	if (!s)
		return (ptr);
	ptr = (char **)ft_memalloc(sizeof (char *) * (get_nbwords(s, ' ') + 1));
	printf("il y a %i mots\n", get_nbwords(s, ' '));
	while (get_nbwords(s, ' ') - tab[0])
	{
		check_quotes(s, tab, ptr);
		while (s && *(s + tab[1]) && *(s + tab[1]) == ' ')
			tab[1]++;
		while (s && *(s + tab[1] + tab[2]) && *(s + tab[1] + tab[2]) != ' ')
			tab[2]++;
		ptr[tab[0]] = ft_strsub(s, tab[1], tab[2]);
		tab[1] += tab[2];
		tab[2] = 0;
		tab[0]++;
	}
	ptr[tab[0]] = NULL;
	return (ptr);
}
