#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
/*
int main(void)
{

	char *s2 = "HolaBuenas";
	char s1[40];
	ft_strcpy(s1, s2);
	printf("s1---> %s", s1);
	return (0);
}*/
