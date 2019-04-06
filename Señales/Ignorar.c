#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>

void ignorar(int);
void main();

void main(){
    if(signal(SIGINT, ignorar) == SIG_ERR){
        perror("No se puede cambiar signal");
    }
    printf("Esperando señal...\n");
    while(1)
	    pause();
}

void ignorar(int nsign){
    char n[50];
    printf("No me voy a salir\n");
    printf("¿Desea que kill -2 funcione?(S/N): ");
    scanf("%s", &n);
    if(n[0] == 's' || n[0] == 'S'){ 
	printf("Señal reestablecida con exito.\nIntente nuevamente.");
	printf("\n");
        signal(SIGINT, SIG_DFL);
    }else{
        printf("Esperando señal...\n");
    }
}

