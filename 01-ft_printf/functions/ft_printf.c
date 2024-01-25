/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:31:35 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/25 13:40:01 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//i = itera el argumento
//j = recibe el lenght que devuelve printf
//si encuentra un %. deja de checkear si hay otros. Alomejor hay un return de mas.

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = validate_format(args, format, i + 1, j);
			i++;
		}
		else
			j = ft_putchar(format[i], j);
		i++;
		if (j == -1 )
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (j);
}
