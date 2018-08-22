#include <time.h>
#include <sys/times.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

main()
 {
    struct tms pb1,pb2;
    clock_t t1,t2;
    long h=0,k=0,cont=0;
    int fd, CLK_TCK;
    t1=times(&pb1);
    for(h==1;h<=10000000;h++)
    {
      fd=open("datos.txt",O_RDONLY);
      close(fd);
    };
    t2=times(&pb2); CLK_TCK=sysconf(_SC_CLK_TCK); 
    printf("\nTiempo real= %g segundos\n",(float)(t2-t1)/ CLK_TCK); 
    printf("Tiempo de uso de la CPU en modo usuario= %g segundos\n",(float)(pb2.tms_utime-pb1.tms_utime)/      CLK_TCK);
}