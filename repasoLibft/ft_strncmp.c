#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	return (0);
}

int main (void)
{
	char *s1 = "ddddda5dddd";
	char *s2 = "dddddaiidddd";
	printf("original---> %d\n", strncmp(s1, s2, 8));
	printf("elmio------> %d\n", ft_strncmp(s1, s2, 8));
	
	return (0);
}
