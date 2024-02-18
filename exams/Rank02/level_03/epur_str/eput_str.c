#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void epur_str(char *s)
{
	int i;

	i = 0;
	while (s[i] == '\t' || s[i] == ' ')
		i++;
	while (s[i])
	{
		if (s[i] == '\t' || s[i] == ' ')
		{
			if (s[i + 1] > ' ' && s[i + 1])
			{
				ft_putchar(' ');
			}
		}
		else if (s[i] != ' ' && s[i] != '\t')
			ft_putchar(s[i]);
		i++;
	}
}

int main(int as, char **av)
{
	if (as == 2)
		epur_str(av[1]);
	ft_putchar('\n');
	return (0);
}
