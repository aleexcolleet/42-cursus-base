#include "libft.h"

char ft_isprint(char arg)
{
    if (arg >= 32 && arg <= 126)
        return (1);
    else
        return (0);
}