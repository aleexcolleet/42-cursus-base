#include "push_swap.h"

void	tiny_sort(t_stack_node **a) // case for 3 length stack
{
	t_stack_node *highest_node;
	
	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

static t_stack_node *find_highest_node(t_stack_node *stack)
{
	int	highest;
	t_stack_node *highest_node;

	if (stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while(stack)
	{
		if (stack->value > highest)
		{
			highest = stack_value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_node(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
