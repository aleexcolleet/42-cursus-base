#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rot_13(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'm')
			s[i] += 13;
		else if (s[i] > 'm' && s[i] <= 'z')
			// s[i] -= 13;
		else if (s[i] >= 'A' && s[i] <= 'M')
			s[i] += 13;
		else if (s[i] > 'M' && s[i] <= 'Z')
			s[i] -= 13;
		ft_putchar(s[i]);
		i++;
	}
}
int main(int args, char **argv)
{
	if (args == 2)
		rot_13(argv[1]);
	ft_putchar('\n');
	return (0);
