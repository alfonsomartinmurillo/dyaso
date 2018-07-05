#include <stdio.h>
#include <signal.h>
#include <time.h>

void fun1(int sig);

void main()
{
	long inicio,final;
	int resultado;
	time(&inicio);
	signal(SIGALRM,fun1);
	alarm(10);
	pause();
	time(&final);
	resultado=(final-inicio);
	printf("\nTiempo final= %d (segundos transcurridos desde las 00:00:00 GMT\n\t\t\t del 1 de enero de 1970)\n",final);
	printf("\n Tiempo en responder= %d (seg)\n",resultado);
}

void fun1(int sig)
{
printf("\nMensaje 1\n");
};
