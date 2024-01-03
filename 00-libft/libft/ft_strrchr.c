#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *s, int c)
{
    char *ptr;

    ptr = NULL;
    while (*s)
    {
        if (*s == (unsigned char)c)
            ptr = (char *)s;
        s++;
    }
    if (c == 0)
        return ((char *)s);
    return (ptr);
}
int main(void)
{
    char str[] = "holaholahola";

    printf("elmio-----> %s\n", ft_strrchr(str, 'o'));
    printf("original--> %s\n", strrchr(str, 'o'));

    return (0);
}