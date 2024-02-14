#include <unistd.h> // For write

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	last_word(char *str)
{
	int	idx;

	idx = ft_strlen(str) - 1;
	while (str[idx] == ' ' || str[idx] == '\t')
		idx--;
	while (str[idx] != '\0' && (str[idx] != ' ' && str[idx] != '\t'))
		idx--;
	idx++;
	while (str[idx] != '\0' && (str[idx] != ' ' && str[idx] != '\t'))
	{
		ft_putchar(str[idx]);
		idx++;
	}
}

int	main(int as, char **av)
{
	if (as == 2)
		last_word(av[1]);
	ft_putchar('\n');
	return (0);
}
