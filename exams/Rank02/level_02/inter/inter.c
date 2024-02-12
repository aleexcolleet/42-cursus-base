#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strchr(char s1, char *s2)
{
	int i;

	i = 0;
	while(s2[i])
	{
		if (s1 == s2[i])
			return (1);
		i++;
	}
	if (s2[i] == s1)
		return (1);
	return (0);
}

void	ft_inter(char *sOG, char *sCh)
{
	int i;
	int j;
	char done[256]; //ascii tab

	j = 0;
	i = 0;
	while(sOG[i])
	{
		if (ft_strchr(sOG[i], sCh))
		{
			if (!(ft_strchr(sOG[i], done)) && j < 256)
			{
				ft_putchar(sOG[i]);
				done[j++] = sOG[i];
			}
		}
		i++;
	}
}

int main(int args, char **argv)
{
	if (args == 3)
		ft_inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
