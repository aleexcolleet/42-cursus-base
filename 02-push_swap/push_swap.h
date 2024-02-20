#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int			value;
	int			current_position;
	int			final_index;
	int			push_price;
	bool		above_median;
	bool		cheapest;
	struct	s_stack_node *target_node;
	struct	s_stack_node *next;
	struct	s_stack_node *prev;
}	t_stack_node; //nombre de la list


//funciones

//errores
void	free_matrix(char **av);
void	free_stack(t_stack_node **stack);
void	error_free(t_stack_node **a, char **av, bool flag_as_2);
int	error_syntax(char *str);
int	error_repe(t_stack_node *a, int n);

//split
static char *get_next_word(char *s, char sep);
static int	count_words(char *s, char sep);
char **ft_split(char *s, char sep);

//stack init
static long ft_atoi(const char *s);
void	stack_init(t_stack_node **a, char **av, bool flag_as_2);

//utils
t_stack_node *find_last_node(t_stack_node *c);
void	append_node(t_stack_node **stack, int n);

#endif
