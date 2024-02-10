#include <stdio.h>
#include <unistd.h>
//hace falta un putstr para retornar el parametro
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strlen(char *s)
{
	int i = 0;

	while(s[i])
	{
		i++;
	}
	return (i);
}

void	ft_swap(char *c, char *x)
{
	char tmp;

	tmp = *c;
	*c = *x;
	*x = tmp;
}
char	*ft_strrev(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str) - 1;
	while(i < len) // para no tocar el del medio si son impares
	{
		ft_swap(&str[i], &str[len]);
		i++;
		len--;
	}
	return (str);
}

int main(int args, char **argv)
{
	if (args == 2)
		ft_putstr(ft_strrev(argv[1]));
	else 
		ft_putstr("WRONG NUMB OF PARAMS");
	ft_putchar('\n');
	return (0);
}
