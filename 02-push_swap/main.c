#include "push_swap.h"
#include <stdio.h>

int main(int as, char **av)
{
	t_stack_node *a;
t_stack_node *b;

	a = NULL;
	b = NULL;
	if (as == 1 || (as == 2 && !av[1][0])) //these are just controls
		return (1);
	else if (as == 2) //also a control
		av = ft_split(av[1], ' ');
	stack_init(&a, av + 1, 2 == as); //stack creation. (av + 1)so that I get rid of .out. First arg is now i = 0;
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
} 
