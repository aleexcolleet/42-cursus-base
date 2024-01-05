#include "libft.h"

/**************************************************************
*						FT_ISPRINT:							  *
*	La función ft_isprint se utiliza para determinar si      *
*	un valor de tipo int representa un carácter imprimible   *
*	de acuerdo con la tabla ASCII extendida (códigos de      *
*	carácter de 32 a 126). Devuelve 1 si el valor es un     *
*	carácter imprimible y 0 si no lo es.				      *
*															  *
*	Argumentos:												  *
*	c: Un valor de tipo int que representa un carácter o	  *
*	código de carácter ASCII.								  *
*															  *
\*************************************************************/

int ft_isprint(char c)
{
    return (c >= 32 && c <= 126);
}