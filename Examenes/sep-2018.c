#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buffer, texto[]=" OSAyD 5 oicicrejE";
    int i, pid, tub[2], tam=strlen(texto)-1;
    if (argc!=2) //El número de argumentos no es correcto
    {
        printf("Argumentos incorrectos\n"); 
        exit(-1);
    }
    
    if(pipe(tub)==-1) // La tubería sin nombre no se genera correctamente
    {
        perror("Error open:");
        exit(-2);
    }
    
    if((pid=fork())==-1) // Genero un fork del proceso
    {
        perror("error en primer fork:"); exit(-3);
    }
    
    if(pid==0) // pid==0 representa proceso hijo (el fork)
    {
        // Se muestra el PID del proceso hijo
        printf("Hijo 0, PID=%d\n",getpid()); 
        fflush(stdout);
        close(tub[0]);
        for(i=0;i<=tam;i++) // Voy a realizar un bucle por el nº de posicioens del texto-1  
        {
           if ((pid=fork())==-1) //Genero un fork en cada iteración
           {
               perror("error en siguente fork:"); exit(-4); // Error y finalización de proceso
           }
           if(pid==0) //Si soy el hijo, la verdad... no hago nada
           {
                printf("Hijo %i, PID=%d\n",i+1,getpid()); 
                fflush(stdout);
                if(i==tam) 
                {
                    close(tub[1]); 
                    break;
                } 
           }
            else
            {
                wait(); //Espero a la finalización de mis hijos
                sleep(1); //Duermo un segundo
                write(tub[1],&texto[i],1); //Escribo una posición en la tubería.
                if (i==0) write(tub[1],argv[1],strlen(argv[1])); //Si estoy en la posición 0
                //escribo tambien el argumento pasado como parámetro.
                close(tub[1]);
                break; //   Salgo del bucle
            }
        } // Fin For
    } // Fin if
    else 
    { // Procesos a realizar por el padre...
        printf("Padre 0, PID=%d\n",getpid()); 
        fflush(stdout);
        close(tub[1]); // Cierro la tubería de escritura
        //Proceso de lectura de la tubería
        while((read(tub[0],&buffer,1))>0) 
        {
            printf("-p-");
            printf("%c",buffer); 
            fflush(stdout);
        }
         printf(".\n");
         close(tub[0]); // Cierro la tubería de lectura
         return 0; // Finalizo de forma exitosa
         printf("Incorrecto\n");
     }
} // Fin programa

        
        