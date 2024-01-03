#include <stdio.h>
#include <string.h>

char *ft_strchr(const char *s, int c)
{
    char *p;

    p = (char *)s;
    if (!p)
        return (0);
    while (*p)
    {
        if ((unsigned char)c == *p)
        {
            return (p);
        }
        p++;
    }
    if (c == 0)
        return (p);
    return (0);
}

int main(void)
{

    char str[] = "como estan los maquinas";
    printf("original---> %s\n", strchr(str, 'a'));
    printf("elmio------> %s\n", ft_strchr(str, 'a'));

    return (0);
}
