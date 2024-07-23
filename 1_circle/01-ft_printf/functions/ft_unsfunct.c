/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:32:30 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/25 13:31:47 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsfunct(unsigned int n, int j)
{
	if (n > 9)
	{
		j = ft_putnbr(n / 10, j);
		j = ft_putnbr(n % 10, j);
	}
	else
	{
		j = ft_putchar(n + '0', j);
	}
	return (j);
}
