#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ulstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		ft_putchar(s[i]);
		i++;
	}
}
int main(int args, char **argv)
{
	if (args == 2)
		ulstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
