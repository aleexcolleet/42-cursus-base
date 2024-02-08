#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(int args, char **argv)
{
	if (args == 3)
	{
		if (ft_strcmp(argv[1], argv[2]) == 0)
			printf("equal\n");
		else
		printf("res-->\t%d\n\n",ft_strcmp(argv[1], argv[2]));
	}
	else
		printf("error");
	return (0);
}
