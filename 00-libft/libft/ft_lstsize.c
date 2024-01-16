#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int i;	
	
	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	print_list(t_list *d)
{
	int a;

	if (a == 1)
		printf("la frase final--->");
	while (d)
	{
		printf(" %s\t", (char *)d->content);
		d = d->next;
	}
	a = 2;
}
int main(void)
{
	t_list *d;
	d = ft_lstnew("hola");
	d->next = ft_lstnew("como");
	d->next->next = ft_lstnew("esta");
	d->next->next->next = ft_lstnew("tuhermana");
	print_list(d);
	printf("\ncon %d nodos", ft_lstsize(d));
	

	free(d);
	return (0);
}
