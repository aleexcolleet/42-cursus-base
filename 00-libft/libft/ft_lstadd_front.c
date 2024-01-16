/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:48:57 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/16 13:10:50 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)//el doble puntero nos permite mover *new. Asi como new nos permite cambiar le valor del nodo al que apunta. Asi como un array de strings, mas o menos.
{
	if (!lst || !new)//why add something to an empty list
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list *list = ft_lstnew("como");
	list->next = ft_lstnew("estamos");

	t_list *node1 = ft_lstnew("hola");
	ft_lstadd_front(&list, node1);

	while (list != NULL)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}

	return (0);
}*/
