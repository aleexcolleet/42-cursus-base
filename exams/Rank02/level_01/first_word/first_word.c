#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	find_word(char *str)
{
	int i;

	if (!str)
	{
		write(1, "\n", 2);
		return ;
	}
	i = 0;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int args, char **argv)
{
	if (args == 2)
		find_word(argv[1]);
	ft_putchar('\n');
	return (0);
}


