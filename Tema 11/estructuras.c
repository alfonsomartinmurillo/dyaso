#include <stdio.h>
typedef struct
{
    long int dni;
    float nota;
} datos;

void cambiar(datos *a);
void main()
{
    datos alumno={70534213, 7.5};
    printf("Datos Previos del alumno\n");
    printf("%ld %.1f\n", alumno.dni, alumno.nota);
    cambiar(&alumno);
    printf("Datos del alumno, una vez cambiados por la función\n");    
    printf("%ld %.1f\n", alumno.dni, alumno.nota);
}

void cambiar(datos *a)
    {
    a->dni=23789345;
    a->nota=8.0;
    return;
    }