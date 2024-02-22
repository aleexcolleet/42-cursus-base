#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_lenght(int nbr)
{
	int i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);

}
char *ft_itoa(int nbr)
{
	int len;

	len = 0;
	if (nbr == -2147483648)
	{
		char MXI = "-2147483648";
		return (MXI);
	}
	len = ft_lenght(nbr)
	printf("%s\n");
	

}
int main(void)
{
	int nbr;
	printf("num?\n");
	scanf("%d", nbr);
	printf("res--> %s", ft_itoa(nbr);
	ft_putchar('\n');
}
