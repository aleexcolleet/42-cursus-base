/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet- <acollet-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:33:14 by acollet-          #+#    #+#             */
/*   Updated: 2024/01/12 15:33:17 by acollet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	contador;
	int	warn;

	contador = 0;
	warn = 0;
	while(*str)
	{
		if (*str != c && warn == 0)
		{
			warn = 1;
			contador++;
		}
		else if	(*str == c)
			warn = 0;
		str++;
	}
	return (contador);
}

static int	len_word(char const *s, char c)
{
	int	counter;

	counter = 0;
	while (*s == c)
		s++;//necesario para cuando la llamo en otras ocasiones
	while (*s != c && *s)
	{
		counter++;
		s++;
	}
	return (counter);
}
static char	**free_m(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);//libero strings de el que falla hacia atras
		--i;
	}
	free(split);//libero el array
	return (NULL);
}
char **ft_split(char const *s, char c)
{
	char	**array;
	int		i; //trabajo strings
	int		j; //contenido de estos
	
	if(!s)
		return(NULL);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[j] == c && s[j] != '\0')
			j++; //para avanzar en caso de que sean iguales
		array[i] = ft_substr(s, j, len_word(&s[j], c));
		if (!array[i])
			return (free_m(array, i));//en caso de que falle alguno, borra todos
		j += len_word(&s[j], c); //adelanto j al siguiente substring
		i++;
	}
	array[i] = 0;
	return (array);
}
/*
int	main(void)
{
	char str[] = "AlexAlohaAlejoAsturias";
	char **str1;
	str1 = ft_split(str, 'A');
	printf("resultado--->");
	while(*str1)
		printf("%s\t", *str1++);
	return(0);
}*/
