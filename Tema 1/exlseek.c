# include <stdio.h>
#include <fcntl.h>
# include <stdlib.h>
# define LL 41

main(int np, char* a[])
{
    int b, id, h;
    char alm[LL+1];

    if (np==3)
    {
        b=atoi(a[2]);
        id=open(a[1],O_RDWR);
        if ((id!=-1)&&(lseek(id,(b-1)*LL,0)!=-1) &&(read(id,alm,LL)>0))
        {
            printf("\n");
            for(h=0;h<LL;h=h+1)
                printf("%c",alm[h]);

        }
        else
            printf("\nError\n");

    } // Fin if número de parámetros
    else

    exit(1);
} // Fin main