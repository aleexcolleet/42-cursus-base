#include "push_swap.h"

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
	stack_init(&a, argv + 1, 2 == as); //stack creation
	if (!stack_sorted(a))//algorithm
}
