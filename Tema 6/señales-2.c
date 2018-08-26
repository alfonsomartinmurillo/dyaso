#include <signal.h>
#include <stdio.h>
#include <string.h>
void manejador(int sig);
void main()
{
    if (signal(SIGUSR1,manejador)==SIG_ERR) 
    {
         perror("\nError");
         exit(1);
    }
    //for (;;);
    printf("En espera a la recepción de señales");
    pause();
}

void manejador (int sig)
{
    printf("Señal recibida desde el inframundo...");
    printf("\n\n%s recibida. \n",strsignal(sig));
    exit(2);
}