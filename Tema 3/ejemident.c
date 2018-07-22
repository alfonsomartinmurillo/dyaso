#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void  main()
{
    int x, y;
    int fd1,fd2;
    x=getuid(); //obtengo el uid del proceso
    y=geteuid(); //obtengo el euid del proceso
    printf("\nUID= %d, EUID= %d \n", x, y); 
    fd1=open("fichero1.txt", O_RDONLY); 
    fd2=open("fichero2.txt", O_RDONLY);
    printf("fd1= %d, fd2= %d \n", fd1, fd2); 
    setuid(x);
    printf("Después del setuid(%d): UID= %d,EUID= %d \n",x,getuid(),geteuid());
    fd1=open("fichero1.txt", O_RDONLY);
    fd2=open("fichero2.txt", O_RDONLY);
    printf("fd1= %d, fd2= %d \n", fd1, fd2);
    setuid(y);
    printf("Después del setuid(%d): UID= %d, EUID= %d \n",y,getuid(),geteuid());
}