#include <stdio.h>
#include <stdlib.h>
#define MAX 256

void main(){
    int fildes[2];
    int pid;
    char mensaje[MAX];
    if(pipe(fildes) == -1){
        perror("error pipe");
	exit(-1);
    }
    if((pid = fork()) == -1){
        perror("Error fork");
	exit(-1);
    }else if(pid == 0){
        while(read(fildes[0], mensaje, MAX) > 0 && strcmp(mensaje, "FIN") != 0){
	    printf("receptor: %s\n", mensaje);
	}
	close(fildes[0]);
	close(fildes[1]);
    }else{
        while(printf("Emisor:") != 0 && scanf("%s", mensaje) != NULL &&                   write(fildes[1], mensaje, strlen(mensaje) +1 ) > 0 &&                             strcmp(mensaje, "FIN") != 0){
	    close(fildes[0]);
	    close(fildes[1]);
	    exit(0);
	}
    }
}
