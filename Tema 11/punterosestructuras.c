#include <stdio.h>
#define T 3
#define NULL 0

typedef struct 
{
	long int dni;
	float nota;
} datos;

datos *buscar(datos a[], long int b);
void main()
{ // Inicio main
    datos alumnos[T]=
                {
                {70534213, 7.5},
                {33356897, 8.5},
                {85963472, 7.0}
                };
    long int id;

    datos *pr;
    tex
    printf("\nIntroduzca el DNI del alumno: "); scanf("%ld", &id);
    pr=buscar(alumnos, id);
    if (pr!=NULL)
    printf("Nota[%ld]= %.1f\n", pr->dni, pr->nota); else
                printf("\nDNI no encontrado");
} // Fin main

datos *buscar(datos a[], long int b)
{
    int h;
    for(h=0;h<T;++h)
    {
        if(a[h].dni==b)
        return(&a[h]);
    }
    return(NULL);
}