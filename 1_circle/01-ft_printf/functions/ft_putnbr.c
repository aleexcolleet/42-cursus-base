/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:32:05 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/25 13:13:51 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int j)
{
	if (j == -1)
		return (-1);
	if (n <= -2147483648)
	{
		j = ft_putchar('-', j);
		j = ft_putchar('2', j);
		j = ft_putnbr(147483648, j);
	}
	else if (n < 0)
	{
		j = ft_putchar('-', j);
		j = ft_putnbr(-n, j);
	}
	else if (n >= 10)
	{
		j = ft_putnbr(n / 10, j);
		j = ft_putnbr(n % 10, j);
	}
	else
		j = ft_putchar(n + '0', j);
	return (j);
}
