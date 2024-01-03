#include <stdio.h>

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    char *pt_src;

    pt_src = (char *)src;
    i = 0;
    j = 0;

    while (i < size && *dst)
    {
        dst++;
        i++;
    }
    if (i == size)
        return (i + ft_strlen(src));
    while (pt_src[j])
    {
        if (j < size - i - 1)
            *dst++ = pt_src[j];
        j++;
    }
    *dst = 0;
    return (i + j);
}
/*
int main(void)
{
    char src[] = "Hola, Alex!";
    char dst[40] = "hola";

    printf("the lenght is : %d\n", ft_strlcat(dst, src, sizeof(dst)));
    printf("el string final: %s\n", dst);

    return (0);
}
*/