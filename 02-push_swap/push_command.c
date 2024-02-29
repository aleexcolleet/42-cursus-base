#include "push_swap.h"


//general fucntion to push nodes betwen lists
static void	push(t_stack node **dest, t_stack_node **src) // node_to_push->next->prev just to ensure its correctly pointed // he de preguntar igual
{
	t_stack_node *node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = *(src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
