/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:31:35 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/25 12:36:15 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//i = itera el argumento
//j = recibe el lenght que devuelve printf

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = -1;
	j = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%", format [i]))
				j = validate_format(args, format, i, j);
		}
		else
			j = ft_putchar(format[i], j);
		if (j == -1)
			return (-1);
	}
	va_end(args);
	return (j);
}
