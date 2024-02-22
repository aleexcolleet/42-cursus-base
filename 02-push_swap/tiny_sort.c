#include "push_swap.h"

void	tiny_sort(t_stack_node **a)
{
	t_stack_node *highest_node;
	
	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node) //este y el siguiente van de la mano
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
	

}
