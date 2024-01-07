#include "libft.h"

/**************************************************************
*						FT_STRJOIN:							  *
*	La función ft_strjoin concatena dos cadenas de caracteres *
*	(s1 y s2) en una nueva cadena de caracteres.              *
*	Devuelve un puntero a la nueva cadena concatenada o NULL  *
*	en caso de error de asignación de memoria.                *
*															  *
*	Argumentos:												  *
*	s1: La primera cadena de caracteres que se concatenará.   *
*	s2: La segunda cadena de caracteres que se concatenará.   *
*															  *
\*************************************************************/

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t i;
    size_t j;
    char *new;

    new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new || !s1 || !s2)
        return (NULL);
    i = 0;
    while (s1[i] != '\0')
    {
        new[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
        new[i++] = s2[j++];
    new[i] = '\0';
    return (new);
}
/*
int main(void)
{
    char const s1[] = "hola buenas";
    char const s2[] = "eso es";
    char *result = ft_strjoin(s1, s2);
    printf("string final: %s", result);
    free(result);

    return (0);
}*/