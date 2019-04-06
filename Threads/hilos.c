#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


int mutex = 0;
int hilo1 = 0;
int hilo2 = 0;


void *hola(void *arg)
{
	char *msg = "Hola";
	int i;
	for(i=0;i<strlen(msg);i++)
	{
		while(mutex==1);
		printf("%c", msg[i]);
		
		fflush(stdout);
		if(hilo2 == 0)		
			mutex=1;
	}
		hilo1 = 1;
		return NULL;
}

void *mundo(void *arg)
{
	char *msg = "mundo";
	int i;
	for(i=0;i<strlen(msg);i++)
	{
		while(mutex==0);		
		printf("%c", msg[i]);
		fflush(stdout);
		if(hilo1 == 0)		
			mutex=0;
	} 
	hilo2 = 1;
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t h1;
	pthread_t h2;
	char c;
	mutex = pthread_create(&h1, NULL, mundo, NULL);
	mutex = pthread_create(&h2, NULL, hola, NULL);
	scanf("%c",&c);
	printf("\nFin\n");

}

