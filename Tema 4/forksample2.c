#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int fichero1, fichero2;
char caracter;
int par;

main (int argc, char *argv[])
 {
    if (argc!=3)
        exit(1);
    fichero1=open(argv[1], O_RDONLY);
    fichero2=creat(argv[2],0666);
    if (fichero1==-1 || fichero2==-1)
        exit(2);
    par=fork();
    leer_escribir();
    exit(0);
} // Fin main

int leer_escribir()
{
    for(;;) 
    {
        printf("\nLectura realizada por %d\n", par);
        if (read(fichero1, &caracter, 1)!=1)
            return(0);
        write(fichero2, &caracter,1);
        printf("\nEscritura realizada por %d\n", par);
    } // Fin For
} // fin leer escribiro