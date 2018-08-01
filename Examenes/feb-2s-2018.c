#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{ // inicio main

    int fd, pid, salida, status;
    if (argc!=2) 
    {
        printf("Argumentos incorrectos\n"); 
        exit(1);
    }
    
    fd=open("fichero1.sh", O_RDWR|O_CREAT|O_TRUNC, 0666);
    if (fd==-1) 
    {
        perror("Error open"); 
        exit(2);
    }
    write(fd,"#!/bin/bash \n echo Ejercicio 5",29);
    write(fd,argv[1],strlen(argv[1]));
    close(fd);
    chmod("fichero1.sh",0700);

    unlink("fifo");
    if (mknod("fifo",S_IFIFO|0666,0)==-1)
    {
        perror("Error mknod"); 
        exit(3);
    }
    if ( (pid=fork())==-1 ) 
    {
        printf("Error fork\n"); 
        exit(4);
    }
    if ( pid==0 )
    {
        salida=system("./fichero1.sh > fifo");
        /*
        printf("Contenido de la cola FIFO \n");
        execl("/bin/cat","cat","fifo",NULL);
        printf("----------------------- \n");        
        */
        if (salida==0) printf("¡Correcto!\n");
        unlink("fifo");
        unlink("fichero1.sh");
    }
    else
    {
        execl("/bin/cat","cat","fifo",NULL);
        perror("Error execl");
        printf("¡Incorecto!\n");
        exit(5);
    }
    
    exit(0);
    
} // fin main