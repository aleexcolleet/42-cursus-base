#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current_a;
	t_stack_node *target_node;
	long	best_match_index;
	
	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match_index) //aqui busca el mayor menor.
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
	if (LONG_MAX == best_match_index) //en caso de no encontrar uno adecaudo. Buscamos el nodo mas pequeno para adherir el mas grande detras de este.
		b->target_node = find_smallest(a);
	else
		b->target_node = target_node;
	b = b->next;
	}
}

