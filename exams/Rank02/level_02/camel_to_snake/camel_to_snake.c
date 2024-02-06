#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	camel_to_snake(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			ft_putchar('_');
			str[i] += ' ';
		}
		ft_putchar(str[i]);
		i++;
	}
}

int main(int args, char **argv)
{
	if (args == 2)
		camel_to_snake(argv[1]);
	ft_putchar('\n');
	return (0);
}
