#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER 256

int main(int argc, char const *argv[]){
    int fd; //Descriptor del archivo
    char *tuberia = "fifo"; //Archivo para la tuberia 

    printf("Productor\n");

    //Se pasa el mensaje por parametro
    if(argc != 2){
        printf("modo de uso: ./Productor mensaje\n");
	exit(-1);
    }
    if(mkfifo(tuberia, 666) == -1){
        printf("Error en la tuberia\n");
	exit(-1);
    }

    printf("Productor en espera que el consumidor se conecte\n");
    if((fd = open(tuberia, O_WRONLY)) == -1){
        printf("Error en la apertura de la tuberia\n");
	exit(-1);
    }

    write(fd, argv[1], BUFFER);
    printf("Productor envio:%s\n", argv[1]);
    close(fd);
    return 0;
}
