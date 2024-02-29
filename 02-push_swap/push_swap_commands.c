#include "push_swap.h"

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);

}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *smallest;
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
}
