#include "libc.h"
/*it converts the int to a str (char *). Negative numbers must be handled
static int is a variable that exist till the end of the program
once initialized. int will be destroyed when the function ends.
long is a data type that can store a single 64-bit signed int.
from -2.147.483.648 to 2.147.483.648
len is +1 because there is null at the end of the string.
is division and % module. The problem of --len is caused by
the differences from position and lenght
*/

static	size_t	ft_counter(long n)
{
    int	i;

	i = 0;
    if (n < 0)
    {
        n *= -1;
        i++;
    }
    while (n / 10 > 0 && i++)
        n = n / 10;
    return (i);
}
char *ft_itoa(int n)
{
    char *str;
    long l;
    size_t len;

    l = n;
    len = ft_counter(l) + 1;
    str = (char *)malloc(sizeof(char) * len);
    if (!str)
        return (NULL);
    if (l < 0)
    {
        l *= -1;
        str[0] = '-';
    }
    str[--len] = '\0';
    if (l == 0)
        str[0] = '0';
    while (l)
    {
        str[--len] = (l % 10) + '0';
        l /= 10;
    }
    return (str);
}
/*
int main(void)
{
    int c = -1234;
    char *result = ft_itoa(c);
    printf("elmio---> %s\n", result);
    free(result);
    return (0);
}*/
