#include "libft.h"

/*						FT_ISALNUM:
 * Determina si un carácter es alfanumérico, es decir,
 * si es una letra (mayúscula o minúscula) o un dígito,
 * y devuelve 1 si es alfanumérico y 0 si no lo es.
 */

int ft_isalnum(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 48 && c <= 57));
}
/*
int main(void)
{
    char check = '6';
    if (ft_isalnum(check) == 1)
    {
        printf("it's an alphanumeric number");
        return (0);
    }
    printf("its nos an alhp");

    return (0);
}*/