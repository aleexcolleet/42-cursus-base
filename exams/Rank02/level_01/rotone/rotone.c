void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'y') || (s[i] >= 'A' && s[i] <= 'Y'))
			s[i] += 1;
		else if (s[i] == 'Z'|| s[i] == 'z')
			s[i] -= 25;
		ft_putchar(s[i]);
		i++;
	}
}

int main(int args, char **argv)
{
	if (args == 2)
		rotone(argv[1]);
	ft_putchar('\n');
	return (0);
}

