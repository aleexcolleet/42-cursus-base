#include "libft.h"

/**************************************************************
*						FT_MEMCPY:							  *
*	La función ft_memcpy copia n bytes de una zona de memoria *
*	origen (src) a una zona de memoria destino (dest).        *
*	Devuelve un puntero a la zona de memoria destino.         *
*															  *
*	Argumentos:												  *
*	dest: Un puntero a la zona de memoria destino donde se    *
*	realizará la copia.										  *
*	src: Un puntero a la zona de memoria origen desde donde   *
*	se copiarán los datos.									  *
*	n: El número de bytes que se copiarán desde src a dest.   *
*															  *
\*************************************************************/

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    if (!dest && !src && n > 0)
        return (NULL);
    return (ft_memmove(dest, src, n));
}
/*
int main(void)
{
    char dest[] = "ooooooo";
    char src[] = "aaaaaaa";

    printf("elmio----> %s", ft_memcpy(dest, src, 5));

    return (0);
}*/