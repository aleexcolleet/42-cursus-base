#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	repeat(char c, int pos)
{
	while (pos >= 0)
	{
		ft_putchar(c);
		pos--;
	}
}

void	repeat_alpha(char *s)
{
	size_t i;
	size_t pos;

	if (!s)
		return ;
	i = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			pos = (s[i] - 'a');
			repeat(s[i], pos);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			pos = (s[i] - 'A');
			repeat(s[i], pos);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
}

int main(int args, char **argv)
{
	if(args == 2)
		repeat_alpha(argv[1]);
	ft_putchar('\n');
	return (0);
}
