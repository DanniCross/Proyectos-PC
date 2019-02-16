#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t hijo;
    int cod_retorno;

    if((hijo = fork()) < 0){
        perror("Error en el fork");
	exit(EXIT_FAILURE);
    }else{
        if(hijo == 0){
	    sleep(30);
	}else{
	    printf("Enviando senal SIGCHLD a %d\n", hijo);
	    cod_retorno = kill(hijo, SIGCHLD);
	    if(cod_retorno < 0){
	        perror("Error kill::SIGCHLD");
	    }else{
	        printf("El proceso %d todavia existe\n", hijo);
		printf("Eliminando al hijo %d\n", hijo);
		if(kill(hijo, SIGTERM) < 0){
		    perror("Error kill::SIGTERM");
		}
		waitpid(hijo, NULL, 0);
	    }
	}
    }
    return 0;
}
