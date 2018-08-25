#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MAX 20

void main() 

{ // Inicio Main
    int shmid, i;

    float *array;

    key_t llave;
    printf("Inicio proceso");
    /* Creación de una llave.*/
    printf("Creación de la llave");
    llave=ftok("prueba",'K');
    /* Petición de una zona de memoria compartida */ 
    printf("Petición Memoria Compartida");
    shmid=shmget(llave,MAX*sizeof(float),IPC_CREAT | 0600);
    /* Unión de la zona de memoria compartida a nuestro espacio de direcciones virtuales. */
    printf("Attach Memoria Compartida");
    array=shmat(shmid,0,0);
    /* Manipulación de la zona de memoria compartida */ 
    for (i=0; i<MAX; i++)
    {
        array[i]=i*i;
    }

    /* 
    Separación de la zona de memoria compartida de nuestro espacio de direcciones virtuales. 
    */
    printf("Detach Memoria Compartida");
    shmdt(array);
    /* Borrado de la zona de memoria compartida */
    printf("Borrado Memoria Compartida");
    shmctl(shmid, IPC_RMID,0);
    printf("Fin proceso");
} // Fin Main