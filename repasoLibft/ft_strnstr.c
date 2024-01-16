#include <stdio.h>
#include <string.h>

char *ft_strnstr(const char *haystack,	const char *needle, size_t len)
{
	char *p1;
	char *p2;
	size_t i;
	size_t x;

	p1 = (char *)haystack;
	p2 = (char *)needle;
	if (!needle || needle[0] == '\0') //needle empty 
		return (p1);
    i = 0;
	x = 0;
	while (p1[i] && i < len) //iterate across  haystack
	{	
		if (p1[i] == p2[x])
		{
			x++;
			i++;
		}
		else if (p2[x + 1] == '\0')
				return (p2 + i - x);
		else
		{
			x = 0;
			i++;	
		}
	}
	return (NULL);
}

int main (void)
{
	char *haystack = "holehola";
	char *needle = "hola";
	printf("resultado ---> %s\n", ft_strnstr(haystack, needle, 15));
	printf("original ----> %s\n", strnstr(haystack, needle, 15));
	return (0);
}
