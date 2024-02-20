#include "push_swap.h"

static char *get_next_word(char *s, char sep)
{
	static int	cursor = 0; //private global variable
	char	*next_str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[cursor] == sep)
		++cursor;
	while ((s[cursor + len] != sep) && s[cursor + len])
		++len;
	next_str = malloc(len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while ((s[cursor] != sep) && s[cursor]) // copy funct
		next_str[i++] = s[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

static int	count_words(char *s, char sep)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == sep && *s)
			++s;
		while (*s != sep && *s)
		{
			if (!inside_word) //already inside the word
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

char **ft_split(char *s, char sep)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(s, sep);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2)); //to add the program name as an argument too, besides the '\0'
	if (!vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (!vector_strings)
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(s, sep); //almacenamos los args en el doble **
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
