#include <stdio.h>

int ft_toupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

int main(void)
{
    int c = 'Z';
    printf("la letra es: %c", ft_toupper(c));
    return (0);
}