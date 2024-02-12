#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	last_word(char *OG, *CH)
{
	
}

int main(int as, char **av)
{
	if (as == 3)
		last_word(av[1], av[2]);
	else
		printf("wrong numb of params");
	return (0);
}
