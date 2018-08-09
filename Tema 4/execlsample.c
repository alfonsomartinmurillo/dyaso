#include <stdio.h>
#include<unistd.h>
main()
{
    char *const argumentos[]={"date",NULL};
    if (fork()==0)
    {
        execv("/bin/date",argumentos);
    }
    printf("\nFinalizar\n");
}

