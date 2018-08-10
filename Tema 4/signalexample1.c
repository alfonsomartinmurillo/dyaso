#include <signal.h>

void main ()
{

    int a;
    if ((a=fork())==0)
    {
        while (1)   
        {
            printf("pid del proceso hijo=%d \n",getpid()); 
            sleep(1);
        }
    }
        sleep(10);
        printf("Terminación del proceso con pid=%d\n",a); 
        kill(a,SIGTERM);
    

}