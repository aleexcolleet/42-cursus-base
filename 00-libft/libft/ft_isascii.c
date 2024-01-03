#include <stdio.h>

char ft_isascii(char z)
{
    if (z >= 0 && z <= 127)
        return (1);
    return (0);
}

int main(void)
{
    char check = 23;
    if (ft_isascii(check) == 1)
    {
        printf("it's an ascii character");
        return (0);
    }
    printf("its not an ascii");

    return (0);
}