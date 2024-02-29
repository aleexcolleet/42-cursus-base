#include "push_swap.h"

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
}
