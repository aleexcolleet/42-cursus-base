#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char mask;

	if (octet[0] == 2)
	{
		ft_putstr("00000010");
		return ;
	}
	

}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
	}
}

int main(int as, char **av)
{
	if (av == 2)
		print_bits(av[1]);
	else
		printf("WRONG PARAMS NUMB");
	return (0);
}
