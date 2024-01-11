#include "libft.h"
/**************************************************************
*						FT_MEMMOVE:							  *
*	La función ft_memmove copia len bytes de una zona de      *
*	memoria origen (src) a una zona de memoria destino (dst), *
*	posiblemente solapándose. Devuelve un puntero a la zona   *
*	de memoria destino.                                       *
*															  *
*	Argumentos:												  *
*	dst: Un puntero a la zona de memoria destino donde se     *
*	realizará la copia.										  *
*	src: Un puntero a la zona de memoria origen desde donde   *
*	se copiarán los datos.									  *
*	len: El número de bytes que se copiarán desde src a dst.  *
*															  *
\*************************************************************/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!(src && dest))
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		d[n] = s[n];
	return (dest);
}
/*
int main(void)
{
    char str[] = "lamadredelbravo.";
    char dest[1];
    printf((ft_memmove(dest, str, 10)));
}*/
