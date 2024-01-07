#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************
*						FT_STRTRIM:								   *
*	La función ft_strtrim elimina los caracteres especificados	   *
*	por el conjunto `set` al principio y al final de una cadena	   *
*	de caracteres `s1`. Devuelve una nueva cadena de caracteres	   *
*	con los caracteres eliminados.                                 *
*																   *
*	Argumentos:													   *
*	s1: La cadena de caracteres de la que se eliminarán los		   *
*	caracteres del conjunto `set`.                                 *
*	set: El conjunto de caracteres que se eliminarán de `s1`.      *
*															       *
*	Devuelve: Un puntero a la nueva cadena de caracteres           *
*	resultante, o NULL si hay un error de asignación de memoria.   *
*															       *
\******************************************************************/

char *ft_strtrim(char const *s1, char const *set)
{
    char *str;
    size_t j;

    if (!s1)
        return (NULL);
    if (!set)
        return ((char *)s1);
    while (*s1 && ft_strchr(set, *s1))
        s1++;
    j = ft_strlen(s1);
    while (j && ft_strchr(set, s1[j]))
        j--;
    str = ft_substr(s1, 0, j + 1);
    if (!str)
        return (NULL);
    return (str);
}

int main(void)
{
    char const s1[] = "hola";
    char const s2[] = "oa";
    char *result = ft_strtrim(s1, s2);
    free(result);
    return (0);
}