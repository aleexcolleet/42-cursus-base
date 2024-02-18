#include <stdio.h>
#include <stdlib.h>

int ft_lenght_arr(int start, int end)
{
	int i;

	i = 0;
	if (start < end)
	{
		i++; //para el primero
		while(start < end)
		{
			i++;
			start++;
		}
	}
	else if (start > end)
	{
		i++;
		while(start > end)
		{
			i++;
			start++;
		}
	}
	return (i);
}

int	*ft_range(int start, int end)
{
	int size;
	int *new;
	int i;

	i = 0;
	size = ft_lenght_arr(start, end);//retorna lenght + el primer int
	new = (int *)malloc(sizeof(int *) * size);
	if (!new)
		return (0);
	while (i < size)
	{
		new[i++] = start++;
	}
	return (new);
}

int main(void)
{	
	int i;
	int *new;

	new = ft_range(0, -3);
	i = 0;
	while(i < 4)
	{
		printf("result--> %d\n", new[i]);
		i++;
	}
	free(new);
	return (0);
}
