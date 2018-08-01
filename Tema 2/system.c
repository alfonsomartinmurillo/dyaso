#include <stdlib.h>
#include <stdio.h>

void main()

{
    int salida;
    salida=system("echo $PATH");
    printf("\n Salida=%d \n",salida);
}