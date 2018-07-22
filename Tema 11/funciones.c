#include <stdio.h>

void f1(int u, int v); /*Prototipo de la función f1*/ 
void f2(int *pu, int *pv); /*Prototipo de la función f2*/ 

void main()
{
    int x=2;
    int y=4;
    printf("\nAntes de la llamada a f1: x=%d y=%d", x, y); 
    f1(x,y);
    printf("\nDespués de la llamada a f1: x=%d y=%d", x, y); printf("\nAntes de la llamada a f2: x=%d y=%d", x, y); 
    f2(&x,&y);
    printf("\nDespués de la llamada a f2: x=%d y=%d", x, y);
         }


void f1(int u, int v)
{
    u=0;
    v=0;
                printf("\nDentro de f1:  x=%d  y=%d", u, v);
                return;
}
void f2(int *pu, int *pv)
{
    * pu=0;
    * pv=0;
    printf("\nDentro de f2: x=%d y=%d", *pu, *pv); return;
}