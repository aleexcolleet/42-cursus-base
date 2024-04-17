#include "get_next_line.h"

int ft_strlen(char *str, char c)
{
	int i = 0;

	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char *ft_strdup(char *str, char c)
{
	int i = 0;
	char *res;

	if (!(res = malloc(sizeof(char) * ft_strlen(str, c) + 1)))
		return (NULL);
	while (str[i] && str[i] != c)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int	ft_check_n(char *buff)
{
	int i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	char *line;
	int readv;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(line = ft_strdup("", 0)))
		return (NULL);
	while (ft_check_n(buff) == -1)
	{
		

	}
	
	return (line);
}

