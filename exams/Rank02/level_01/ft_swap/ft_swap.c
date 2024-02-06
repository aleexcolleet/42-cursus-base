#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
/*
int main(void)
{
	int a =  23;
	int b =  44;
	ft_swap(&a, &b);
	ft_swap(&a, &b);
	printf("a---> %d\nb--->%d\n", (int)a, (int)b);
	return (0);
}*/
