#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int max(int *tab, unsigned int len)
{
	if (len <= 0 || tab == 0)
		return (0);
	int i;
	int j;

	j = 0;
	i = 0;
	while(tab[i] && len > 0)
	{
		if (j < tab[i])
			j = tab[i];
		i++;
		len--;
	}
	return (j);
}

int	main(void)
{
	int	arr[4];

	arr[0] = 7;
	arr[1] = 8;
	arr[2] = 4;
	arr[3] = 3;
	ft_putchar(max(arr, 4) + '0');
	ft_putchar(10);
	ft_putchar(max(NULL, 4) + '0');
	ft_putchar('\n');
	return (0);
}

/*
int main(void)
{
	int arr[] = {1, 2, 6, 10, 5};
	printf("result---> %d\n", max(arr, 5));
	return (0);
}*/
