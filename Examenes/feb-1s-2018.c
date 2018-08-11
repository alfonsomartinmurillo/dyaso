#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void manejador(int sig)
{
   execl("/bin/cat","cat","texto.txt",NULL);
   perror("Error execl");
   printf("¡Incorecto!\n");
   exit(1);
}

int main(int argc, char *argv[])
{
   int fd, pid, salida, status;
   if (argc!=2) {printf("Argumentos incorrectos\n"); exit(2);}
   if ( (pid=fork())==-1 ) {printf("Error fork\n"); exit(3);}
   if ( pid==0 )
       {
       if (signal(SIGUSR1,manejador)==SIG_ERR)
           {perror("Error signal"); exit(4);}
       pause();
       printf("¡Erroneo!\n");
} else
        {
        sleep(1);
        fd=open("texto.txt", O_RDWR|O_CREAT|O_TRUNC, 0666);
        if (fd==-1) {perror("Error open"); exit(5);}
        write(fd,"Ejercicio 5 ",12);
        write(fd,argv[1],strlen(argv[1]));
        close(fd);
        kill(pid,SIGUSR1);
        wait(&status);
        printf(" ¡Correcto!\n");
        unlink("texto.txt");
        }
exit(0); }