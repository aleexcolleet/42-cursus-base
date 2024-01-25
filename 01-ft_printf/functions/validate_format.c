/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:32:51 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/25 13:57:31 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	validate_format(va_list args, char const *format, int i, int j)
{
	if (format[i] == 'c')
		j = ft_putchar(va_arg(args, int), j);
	else if(format[i] == 's')
		j = ft_putstr(va_arg(args, char *), j);
	else if (format[i] == 'p')
		j = print_adress(va_arg(args, void *), j);
	else if (format[i] == 'd' || format[i] == 'i')
		j = ft_putnbr(va_arg(args, int), j);
	else if (format[i] == 'u')
		j = ft_unsfunct(va_arg(args, unsigned int), j);
	else if (format[i] == 'x' || format[i] == 'X')
		j = ft_puthexa(va_arg(args, unsigned int), format, i, j);
	else
		j = ft_putchar(format[i], j);
	if (j == -1)
		return (-1); //por lo que putchar a funcionado correctamente
	return (j);

//j = -1; se ha imprimido
//j = 1; no se imprimio
}
