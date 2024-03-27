# include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static double	ft_power(double base, int exponent) {
    double result = 1.0;
    int i;

    if (exponent < 0) {
        // Exponente negativo
        for (i = 0; i > exponent; i--) {
            result *= base;
        }
        return 1.0 / result;
    } else {
        // Exponente positivo
        for (i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }
}

double ft_strtod(const char *str, char **endptr) {
    double result = 0.0;
    int sign = 1;
    int has_integer_part = 0;
    int has_decimal_part = 0;
    int has_exponent_part = 0;
    int exponent_sign = 1;
    int exponent_value = 0;
    double decimal_scale = 0.1;

    // Saltar espacios iniciales
    while (isspace(*str))
        str++;

    // Verificar el signo
    if (*str == '+' || *str == '-') {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // Procesar la parte entera
    while (isdigit(*str)) {
        result = result * 10 + (*str - '0');
        has_integer_part = 1;
        str++;
    }

    // Procesar la parte decimal
    if (*str == '.') {
        str++;
        while (isdigit(*str)) {
            result += (*str - '0') * decimal_scale;
            decimal_scale *= 0.1;
            has_decimal_part = 1;
            str++;
        }
    }

    // Procesar la parte del exponente
    if (*str == 'e' || *str == 'E') {
        str++;
        if (*str == '+' || *str == '-') {
            if (*str == '-')
                exponent_sign = -1;
            str++;
        }
        while (isdigit(*str)) {
            exponent_value = exponent_value * 10 + (*str - '0');
            has_exponent_part = 1;
            str++;
        }
        exponent_value *= exponent_sign;
    }

    // Completar la conversión
    result *= sign;

    // Actualizar el puntero al primer carácter no convertido
    if (endptr != NULL)
        *endptr = (char *)str;

    // Comprobar si se pudo convertir algún componente
    if (!has_integer_part && !has_decimal_part)
        return 0.0;

    // Aplicar la parte del exponente si existe
    if (has_exponent_part)
        result *= ft_power(10, exponent_value);

		return result;
}
