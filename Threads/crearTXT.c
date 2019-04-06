#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int s = 2;

int main(int argc, char** argv){
    FILE *fp;
    fp = fopen("/run/media/josec/Jose Cruz/Documentos/VIMProjects/Threads/archivo.txt","a");
    pthread_t h1;
    pthread_t h2;
}
