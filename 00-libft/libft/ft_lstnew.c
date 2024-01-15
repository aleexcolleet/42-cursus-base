#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *new;
	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (new)
	{
		new->content = content;
		new->next = 0;
	}
	return (new);
}
/*
void	print_list(t_list *node)
{
	while (node)
	{
		printf("node----> %s\n", (char *)node->content);
		node = node->next;
	}
}

int main(void)
{
	t_list *d;
	d = ft_lstnew("hola");
	d->next = ft_lstnew("7227");
	d->next->next = ft_lstnew("hoalhoasdjasdl");
	print_list(d);
}*/
