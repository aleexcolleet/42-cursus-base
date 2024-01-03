#include <stdio.h>
#include <stddef.h>

char ft_isdigit(char z)
{
    if (z >= '0' && z <= '9')
        return (1);
    return (0);
}

int main(void)
{
    int check = '4';
    if (ft_isdigit(check) == 1)
    {
        printf("it's a numeric character");
        return (0);
    }
    printf("its not");

    return (0);
}