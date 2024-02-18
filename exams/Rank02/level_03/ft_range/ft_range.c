#include <stdio.h>
#include <stdlib.h>


int	ft_check_value(int n)
{
	if (n < 0)
		return (n *= -1);
	return (n);
}

int *ft_range(int start, int end)
{
	int idx;
	int size;
	int *new;

	idx = 0;
	size = ft_check_value(start - end);
	new = (int *)malloc(sizeof(int *) * size + 1); //we add here the start value
	if (!new)
		return (0);
	while (start < end)
	{
		new[idx] = start;
		idx++;
		start++;
	}
	while (start > end)
	{
		new[idx] = start;
		start--;
		idx++;
	}
	new[idx] = start;
	return (new);
}

int main(int as, char **av)
{
	int *new;
	int i;

	i = 0;
	if (as == 3)
	{
		new = ft_range((int)av[1][0], (int)av[2][0]);
		printf("result\n\n");
		while (new[i])
		{
			printf("[---> %c\n", new[i]);
			i++;
		}
		free(new);
	}
	else
		printf("WRONG PARAMS NUMB");
	return (0);
}
