#include <stdio.h>

int main() 

{
    
    int par;
    int x=0;
    if ((par=fork())==-1)   
    {
        
        printf("Error en la ejecución del fork");
        exit (-1);
    }
    else if (par==0)
    {
        // Código ejecutado por el hijo
        x=x+2;
        printf("\nProceso hijo, x= %d\n", x);
    }
    else
    {
        // Código ejecutado por el padre
        printf("\nProceso padre, x= %d\n", x);
    }
    
    // Código ejecutado por el padre y el hijo
    printf("\nProceso finalizado\n");
    exit(0);
    
    
} // Fin programa