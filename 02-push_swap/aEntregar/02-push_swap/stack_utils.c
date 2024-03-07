/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:48:38 by acollet-          #+#    #+#             */
/*   Updated: 2024/03/07 12:48:39 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack_node *stack)
{
	int count;
	
	count = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

t_stack_node *find_smallest(t_stack_node *stack)
{
	long		smallest;
	t_stack_node *smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}
