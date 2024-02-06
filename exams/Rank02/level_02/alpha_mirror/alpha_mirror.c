#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	alpha_mirror(char *s)
{
	int pos;
	int i;

	i = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = ('M' - (s[i] - 'N'));
		else if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = ('m' - (s[i] - 'n'));
		ft_putchar(s[i]);
		i++;
	}

}
int main(int args, char **argv)
{
	if (args == 2)
		alpha_mirror(argv[1]);
	ft_putchar('\n');
	return (0);
}
