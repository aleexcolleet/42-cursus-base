#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
char *ft_strjoin(char const *s1, char const *s2)
{
    size_t i;
    size_t j;
    char *p;
    size_t total;

    total = (ft_strlen(s1) + ft_strlen(s2));
    i = 0;
    j = 0;
    if (!(s1[i] || s2[i]))
        return (0);
    p = (char *)malloc(total * sizeof(char));
    while (s1[i] || s2[j])
    {
        if (s1[i])
            p[i] = s1[i];
        else
            p[i + j] = s2[i];
    }
    return (p);
}
int main(void)
{
    char const s1[] = "hola buenas";
    char const s2[] = "eso es";
    char *result = ft_strjoin(s1, s2);
    printf("string final: %s", result);
    free(result);

    return (0);
}