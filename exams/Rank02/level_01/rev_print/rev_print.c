#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rev_print(char *s)
{
	size_t i;

	if (!s)
		return ;
	i = 0;
	while(s[i])
		i++;
	i--;
	while(s[i])
	{
		ft_putchar(s[i--]);
	}
}

int main(int args, char **argv)
{
	if (args == 2)
		rev_print(argv[1]);
	ft_putchar('\n');
	return (0);
}

