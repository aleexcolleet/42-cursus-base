#include "libft.h"

/*s is the str to be split. c is the delimiter char.
The function return the array of new strs resulting from the split. NULL
if the allocation fails.
*/
static char *function_2(const char *str, int start, int end)
{
    char *rtn;
    int i;

    rtn = (char *)malloc(sizeof(char) * ((end - start) + 1))
        i = 0;
    while (start < end)
        rtn[i++] = str[start++];
    rtn[i] = 0;
    return (rtn);
}

static int function_1(const char *str, char c) // para que solo pueda usarse en este archivo. Entiendo porqe es un nombre comun y puede haber problemas con otros programas;
{
    int counter;
    int warn;

    counter = 0;
    warn = 0;
    while (*str)
    {
        if (*str != c && warn == 0)
        {
            warn = 1;
            counter++;
        }
        else if (*str == c)
            warn = 0;
        str++;
    }
    return (counter);
}
static int function_3(const char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char **ft_split(char cosnt *s, char c)
{
    char **out;
    int i;
    int start;
    int j;

    if (!s)
        return (NULL);
    out = (char **)malloc(sizeof(char *) * (function_1(s, c) + 1));
    if (!out)
        return (NULL);
    start = -1;
    i = -1;
    j = 0;
    while (++i <= function_3(s)) // i = 0; start = 0;
    {
        if (s[i] != c && start < 0)
            start = i;
        else if (start >= 0 && (s[i] == c || i == function_3(s)))
        {
            out[j++] = function_2(s, start, i);
            start = -1;
        }
    }
}

/*
int main(void)
{
    char str[] = "dajedajedaje";
    char **str1;
    str1 = ft_split(str, 'd');
    while (*str1)
    {
        printf("%s\n", *str1++);
    }
}*/