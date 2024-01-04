#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[] = "como estatuhermana";
    char *result = ft_substr(str, 5, 8);

    printf("elmio---> %s\n", result);
    free(result);

    return 0;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *new;

    if (!s)
        return NULL;
    if (start >= ft_strlen(s))
        return ft_strdup("");
    if ((ft_strlen(s) - start) < len)
        len = ft_strlen(s) - start;
    new = (char *)malloc((len + 1) * sizeof(char));
    if (!new)
        return NULL;
    ft_strlcpy(new, s + start, len + 1);
    return new;
}
