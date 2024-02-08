#include <stdio.h>

int ft_strchr(const char *cha, char c)
{
	int i = 0;
	char *str = (char *)cha;

	while(str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strpbrk(const char *s, const char *charset)
{
	int i = 0;
	char *ss = (char *)s;
	char *cha = (char *)charset;
	
	while(s[i])
	{
		if (ft_strchr(charset, s[i]))
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int main(int args, char **argv)
{
	if (args == 3)
		printf("res--> %s\n", ft_strpbrk(argv[1], argv[2]));
	else
		printf("WRONG PARAMENTER NUMB\n");
	return (0);
}
