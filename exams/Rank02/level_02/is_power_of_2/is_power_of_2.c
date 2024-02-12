#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned long i;
	i = 1;
	while(i <= n)
	{
		if (i == n)
			return (1);
		i *= 2;
	}
	return (0);
}
/*
int main(void)
{
	int i = 1;
	int a = 1;

	while (i < 100)
	{
		printf("%d: %d---> %d", i, a, is_power_of_2(a));
		i++;
		a++;
		printf("\n");
	}
	printf("\n");
}*/
