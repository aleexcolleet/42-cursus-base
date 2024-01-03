#include <stdio.h>

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t k;

    i = 0;
    if (!little || little[i] == '\0')
        return ((char *)big);
    while (big[i] && i < len)
    {
        k = 0;
        while (big[i + k] == little[k])
        {
            if (!little[k + 1])
                return ((char *)big + i);
            k++;
        }
        i++;
    }
    return (0);
}

int main(void)
{
    char big[] = "holabuenas";
    char little[] = "buenas";
    printf("elmio---> %s", ft_strnstr(big, little, sizeof(big)));
    return (0);
}