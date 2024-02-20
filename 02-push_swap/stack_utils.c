#include "push_swap.h"

t_stack_node *find_last_node(t_stack_node *c)
{
	if (c == NULL)
		return (NULL);
	while (c->next)
		c = c->next;
	return (c);
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node *node;
	t_stack_node *last_node;

	if (stack == NULL) //here I check if the pointer itself is null, meaning it doesnt point to any valid adress
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (*stack == NULL)
	{
		*stack = node; //t_stack_node 'a' points to the new "node" now;
		node->prev = NULL;
	}
	else 
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
