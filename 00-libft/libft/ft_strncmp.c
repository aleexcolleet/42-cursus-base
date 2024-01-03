#include <stdio.h>
#include <string,h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char *ptr1;
    unsigned char *ptr2;

    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    while (n && *ptr1 && *ptr1 == *ptr2)
    {
        ++ptr1;
        ++ptr2;
        --n;
    }
    if (n)
        return (*ptr1 - *ptr2);
    else
        return (0);
}

int main(void)
{
    char s1[] = "hola";
    char s2[] = "hola";
    printf("original---> %s", strncmp(s1, s2, 5));
    printf("el mio-----> %s", ft_strncmp(s1, s2, 5));
    return (0);
}