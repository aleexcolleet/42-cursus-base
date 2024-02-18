#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hidenp(char *OG, char *CH)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (CH[k])
	{
		if (!OG[i])
		{
			ft_putchar('1');
			return ;
		}
		else if (OG[i] == CH[k])
			i++;
		k++;
	}
	ft_putchar('0');	
}
/*
int main(int as, char **av)
{
	if (as == 3)
		hidenp(av[1], av[2]);
	else
		printf("wrong params numb");
	ft_putchar('\n');
	return (0);
}*/
