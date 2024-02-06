#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	search_and_replace(char *s, char *c, char *x)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == *c)
			s[i] = *x;
		ft_putchar(s[i]);
	}

}

int main(int args, char **argv)
{
	if (args == 4)
	{
		printf("orig--> %s\n", argv[1]);
		search_and_replace(argv[1], argv[2], argv[3]);
	}
	ft_putchar('\n');
	return (0);
}
