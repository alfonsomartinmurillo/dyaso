#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 256
void main() 

{ // Inicio Main
    int tuberia[2];
    int pid;
    char mensaje[MAX];
    
    if (pipe(tuberia)==-1) // Intento crear la tubería
    {
        perror("pipe"); //Descripción de error
        exit(-1); // El programa finaliza
    }
    
    if ((pid=fork())==-1) // Genero un fork del proceso
    {
        perror("fork");
        exit(-1);
        
    }
    else if (pid==0) //proceso hijo
    {
        // tuberia[0] representa el descriptor de la tubería para leer
        while (read(tuberia[0], mensaje, MAX)>0 && strcmp(mensaje,"FIN")!=0)
            printf("\nProceso receptor. Mensaje: %s\n", mensaje); // una única linea
        close(tuberia[0]);
        close(tuberia[1]);
        exit(0);
    }
    else //proceso padre
    {
        while 
            (
                printf("Proceso emisor. Mensaje: ")!=0
                && gets(mensaje)!=NULL
                && write(tuberia[1], mensaje,strlen(mensaje)+1)>0
                && strcmp(mensaje,"FIN")!=0
            ); // Solicito información hasta que la entrada sea FIN. Dicha información es tratada
                // por el proceso Fork.
        close(tuberia[0]);
        close(tuberia[1]);
        exit(0);
    }
    
} // Fin main