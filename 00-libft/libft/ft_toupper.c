#include <stdio.h>

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int main(void)
{
    int c = 'z';
    printf("la letra es: %c", ft_toupper(c));
    return (0);
}