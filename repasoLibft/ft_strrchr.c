#include <stdio.h>
#include <stdlib.h>

char *ft_strrchr(const char *s, int c)
{
	char *str;
	
	str = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			str = ((char *)s);
		}
		s++;
	}
	if (*s == (char )c)
		str = (char *)s;
	return (str);
	
}
int main (void)
{
	char str[] = "como estan los maquinas";
    printf("elmio------> %s\n", ft_strrchr(str, '\0'));
	return (0);
}
