              **************** "FT_PRINTF" ******************

"COMO FUNCIONA":
Recibe dos argumentos: El primero es una cadena que especifica cómo debe formatearse la salida. El segundo es un número variable de argumentos, que son los valores que se formatearán e imprimirán (así es como funciona la función real).

"REALIZARA LAS SIGUIENTES CONVERSIONES":
- %c     Imprime un solo carácter.
- %s     Imprime una string (como se define por defecto en C).
- %p     El puntero void * dado como argumento se imprime en formato hexadecimal.
- %d     Imprime un número decimal (base 10).
- %i     Imprime un entero en base 10.
- %u     Imprime un número decimal (base 10) sin signo.
- %x     Imprime un número hexadecimal (base 16) en minúsculas.
- %X     Imprime un número hexadecimal (base 16) en mayúsculas.
- %%     Imprime el símbolo del porcentaje.

"LAS FUNCIONES EXTERNAS AUTORIZADAS":
- malloc     Solicitar un bloque de memoria del tamaño suministrado como parámetro.
- free     Desasigna un bloque de memoria que se había asignado previamente mediante una llamada.
- write     Hace que los bytes que indiques del buffer sean escritos en el file descriptor seleccionado.
- va_start     Permite el acceso a los argumentos de la función variada.
- va_arg     Accede al siguiente argumento de la función variada.
- va_copy     Hace una copia de los argumentos de la función variádica.
- va_end     Finaliza el recorrido de los argumentos de la función variada 
