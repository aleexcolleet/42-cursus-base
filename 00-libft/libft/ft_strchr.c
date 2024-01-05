#include "libft.h"

/**************************************************************
*						FT_STRCHR:							  *
*	La función ft_strchr busca la primera aparición de un     *
*	carácter (c) en una cadena de caracteres (s).             *
*	Devuelve un puntero al carácter encontrado o NULL si el   *
*	carácter no se encuentra en la cadena.                    *
*															  *
*	Argumentos:												  *
*	s: La cadena de caracteres en la que se realizará la      *
*	búsqueda.												  *
*	c: El carácter que se buscará en la cadena.               *
*															  *
\*************************************************************/

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0' && (char)c != *s)
        s++;
    if ((char)c == *s)
        return ((char *)s);
    return (0);
}
/*
int main(void)
{

    char str[] = "como estan los maquinas";
    printf("original---> %s\n", strchr(str, 'a'));
    printf("elmio------> %s\n", ft_strchr(str, 'a'));

    return (0);
}*/
