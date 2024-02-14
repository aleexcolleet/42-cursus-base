#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	last_word(char *OG)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (OG[i])
		i++;
	while (OG[i] && (OG[i] >= 9 && OG[i] <= 13) || OG[i] == 32 || OG[i] == '\0')
		i--;
	while (!((OG[i] >= 9 && OG[i] <= 13) || OG[i] == 32))
	{
		i--;
		x++;
	}
	i++; //para el ultimo
	while(x > 0)
	{
		ft_putchar(OG[i]);
		i++;
		x--;
	}	
}

int main(int as, char **av)
{
	if (as == 2)
		last_word(av[1]);
	else
		printf("wrong numb of params");
	ft_putchar('\n');
	return (0);
}
