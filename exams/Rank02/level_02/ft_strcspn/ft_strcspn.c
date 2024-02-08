#include <stddef.h> // For NULL || (void *)0 || 0

//it simply checks if there are non wanted(rejected) characters on (char *)s;
int	ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (ft_strchr(reject, s[idx]))
			break ;
		idx++;
	}
	return (idx);
}

#include <stdio.h>

int	main(int args, char **argv)
{
	if (args == 3)
		printf("result---> \t%lu", ft_strcspn(argv[1], argv[2]));
	else
		printf("WRONG PARAMETER NUMB\n");
	return (0);
}

