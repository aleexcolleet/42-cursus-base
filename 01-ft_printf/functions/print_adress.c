/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:32:45 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/25 12:32:47 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_adress_hex(unsigned long long vptr, int j)
{
	char	*hex;
	int		result[20];
	int		y;
	
	if (j == -1)
		return (-1);
	hex = "0123456789abcdef";
	y = 0;
	while (vptr >= 16)
	{
		result[y] = hex[vptr % 16];
		vptr = vptr / 16;
		y++;
	}
	result[y] = hex[vptr];
	while (y >= 0)
	{
		j = ft_putchar(result[y], j);
		y--;
	}
	if (j == -1)
		return (-1);
	return(j);
}

int	print_adress(void *ptr, int j)
{
	if (ptr == NULL)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		j += 3;
		return (j);
	}
	j = ft_putstr("0x", j);
	j = print_adress_hex((unsigned long long)ptr, j);
	return (j);
}
