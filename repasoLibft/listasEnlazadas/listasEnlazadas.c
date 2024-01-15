#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	char *content;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(char *content)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		new->content = content;
		new->next = 0;
	}
	return (new);
}
void	print(t_list *node)
{
	while (node)
	{
		printf("node---> %s\n", node->content);
		node = node->next;
	}
}

int main(void)
{
	t_list *d;
	d = ft_lstnew("hola");
	d->next = ft_lstnew("777");
	d->next->next = ft_lstnew("comoestamos");
	print(d);
}
