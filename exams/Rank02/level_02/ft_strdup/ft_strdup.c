#include <stdlib.h>

int	ft_strlen(const char *s1)
{
	int i;
	char *str = (char *)s1;
	i = 0;
	while (str[i])
	{ 
		i++;
	}
	return (i);
}

char *ft_strdup(const char *s1)
{
	int i;
	char *new;

	i = 0;
	if (s1[i])
	{
		new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
		if (!new)
			return (NULL);
		//copiamos
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = '\0';
	}
	else
		return ("nothing was written");
	return (new);
	
}

#include <stdio.h>
int main(int args, char **argv)
{
	char *str;

	if (args == 2)
	{
		str = ft_strdup(argv[1]);
		printf("result---> %s\n", str);
		free(str);
	}
	else
		printf("WRONG PARAMENTERS NUMB");
	return (0);
}
