#include <stdio.h>
#include <math.h>

// Ojo, compilar con -lm

 float a1(float (*b)(float a));
 float a2(float a);
 void main(){
        float z=0;
        z=a1(a2);
        printf("\n%.2f\n",z);
 }
 float a1(float (*b)(float a))
 {
        float u=1;
        u=(*b)(u);
        u=cos(u);
        return(u);
 }
 float a2(float a){
        float v=0;
        v=sin(a);
        return(v);
}