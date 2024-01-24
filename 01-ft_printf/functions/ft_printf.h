#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int			ft_printf(char const *format, ...);
int			ft_putchar(char c, int j);
int			validate_format(va_list args, char const *format, int i, int j);
char		*ft_strchr(const char *str, int c);
int			ft_putstr(const char *str, int j);
static int 	print_adress_hex(unsigned long long vptr, int j);
int			print_adress(void *ptr, int j);
int  ft_putnbr(int n, int j);
#endif
