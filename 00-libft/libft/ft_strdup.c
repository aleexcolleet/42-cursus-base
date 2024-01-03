#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *s)
{
    int i;
    char *p;

    i = ft_strlen(s);
    p = (void *)malloc((i + 1) * sizeof(char));

    if (p == NULL)
        return (0);

    i = 0;
    while (s[i])
    {
        p[i] = s[i];
        i++;
    }
    p[i] = '\0';
    return ((char *)p);
}
int main(void)
{
    const char str[] = "hola";
    char *result = ft_strdup(str);
    printf("elmio---> %s", result);
    free(result);

    return (0);
}