/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:31:58 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/27 11:22:20 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if (n <= 9)imprime el correspondiente

#include "ft_printf.h"

int	ft_printhex(unsigned int n, const char *format, int i, int j)
{
	if (n >= 16)
	{
		j = ft_printhex(n / 16, format, i, j);
		j = ft_printhex(n % 16, format, i, j);
	}
	else
	{
		if (n <= 9)
			j = ft_putchar((n + '0'), j);
		else
		{
			if (format[i] == 'x')
				j = ft_putchar((n - 10 + 'a'), j);
			if (format[i] == 'X')
				j = ft_putchar((n - 10 + 'A'), j);
		}
	}
	return (j);
}

int	ft_puthexa(unsigned int n, const char *format, int i, int j)//principal
{
	if (n == 0)
	{	
		j += write(1, "0", 1);
		return (j);
	}
	else
		j = ft_printhex(n, format, i, j);
	return (j);
}
