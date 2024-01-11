#include <stdio.h>
#include <stdlib.h>

char *ft_strchr(const char *s, int c)
{
	char *ps;

	ps = (char *)s;
	while (*ps++)
	{
		if(*ps == c)
			return (ps);
	}
	return (0);

}

int main(void)
{
	char s[] = "hol4ahoalahola";
	int c = '4';
	printf("resultado---> %s\n", ft_strchr(s, c));
	return (0);
}
