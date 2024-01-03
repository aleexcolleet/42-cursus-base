#include <stdio.h>

char ft_isalnum(char z)
{
    if ((z >= 'a' && z <= 'z') || (z >= 'A' && z <= 'Z') || (z >= '0' && z <= '9'))
        return (1);
    return (0);
}

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
}