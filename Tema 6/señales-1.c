#include <signal.h>
void main ()
{
    int a;
    if ((a=fork())==0) // Genero proceso hijo.
    { // Código asociado a proceso hijo (pid 0)
        while (1)
        {
            printf("pid del proceso hijo=%d \n",getpid());
            sleep(1);
        }
    } // Fin if. 
        sleep(10); // El padre se duerme 10 segundos y envía señal de terminación al hijo
        printf("Terminación del proceso con pid=%d\n",a); kill(a,SIGTERM);
    
} // Fin programa