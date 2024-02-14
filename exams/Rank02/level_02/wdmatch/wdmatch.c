#include <unistd.h> // For write

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

void	ft_wd_match(char *first, char *second)
{
	int fir = 0;
	int sec = 0;

	while (second[sec])
	{
		if (first[fir] == second[sec])
			fir++;
		sec++;
	}
	if (fir == ft_strlen(first))
		ft_putstr(first);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_wd_match(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
