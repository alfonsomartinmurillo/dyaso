#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
    int ident,h,cont=0;
    char buffer[100];
    for (h=0;h<100;h++)
        buffer[h]='\0';
    if((ident=open("escribir.txt",O_WRONLY|O_APPEND))==-1)
    {
        printf("\nError de apertura\n");
        exit(1);
    }
    
    while (cont<98)
    {
        buffer[cont]=getchar();
        if (buffer[cont]=='\n') break;
        cont=cont+1;
    }
        if (cont==98) buffer[cont]='\n';
        write(ident,buffer,100);
        close(ident);   

}
