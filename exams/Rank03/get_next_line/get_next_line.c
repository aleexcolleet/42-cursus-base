#include "get_next_line.h"

//ft_strcpy takes a dst and src string and copies it. Doesn't returnanything cause it changes directly the pointer
void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

//ft_strdup allocates memory and returns a char *
char *ft_strdup(const char *src)
{
	size_t	len = ft_strlen(src);
	char	*dst = malloc(len * sizeof(char));

	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

char *get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			countread;
	int			to_copy;

	line = ft_strdup(buf);
	while (!(newline = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)))
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (0);
}
