
#include "libft.h"

/*						FT_BZERO:
 *	Establece todos los bytes de un bloque de memoria a cero.
 *	Es útil para inicializar o "borrar" la memoria de manera eficiente.
 */

void ft_bzero(void *s, size_t n)
{
    ft_memset(s, '\0', n);
}
/*
int main()
{
    int n = 4;
    char str[] = "Helloooooo";
    ft_bzero(str, n);

    return 0;
}*/