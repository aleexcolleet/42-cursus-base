#include <stdio.h>
#include <unistd.h>

int ft_is_delim(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int ft_len_word(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!ft_is_delim(str[i]))
			len++;
		i++;
	}
	return (len);
}

char *ft_get_word(char *str)
{
	int i;
	char *word;

	i = 0;
	while (str[i] && !ft_is_delim(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (idx + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !ft_is_delim(str[i]))
	{
		word[i] = str[i];

	}
}

char **ft_split(char *str)
{
	int i;
	char **new;

	i = 0;
	if (!(new = (char **)malloc(sizeof(char *) * ft_len_word(str) + 1));
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_delim(*str))
			str++;
		if (*str && !ft_is_delim(*str))
		{
			new[i] = ft_get_word(str);
			i++;
		}

	}

}
