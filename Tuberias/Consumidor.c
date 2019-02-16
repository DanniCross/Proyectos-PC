#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER 256

int main(){
    char mensaje[BUFFER];
    char *tuberia = "fifo";
    int fd;

    printf("Consumidor\n");
    if((fd = open(tuberia, O_RDONLY)) == -1){
        printf("Error en la apertura de la tuberia\n");
	exit(-1);
    }   
    read(fd, mensaje, BUFFER);
    printf("Consumidor recibido:%s\n", mensaje);
    close(fd);
    unlink(tuberia);
}
