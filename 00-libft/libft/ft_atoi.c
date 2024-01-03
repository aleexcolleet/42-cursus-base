#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) // evita los espacios
        i++;
    if (str[i] == '-' || str[i] == '+') // calcula el signo real
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
        result = result * 10 + str[i++] - '0'; // suma digito y canvia a int
                                               // str[i++] - '0';
    return (result * sign);
}

int main(int argc, char **argv)
{

    if (argc != 2)
        return (0);
    printf("atoi orignial----> %d\n", atoi(argv[1]));
    printf("elmio------------> %d\n", ft_atoi(argv[1]));
    return (0);
}