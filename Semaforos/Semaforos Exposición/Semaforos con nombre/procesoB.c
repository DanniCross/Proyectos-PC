#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

int main(void) {
    sem_t *semA;
    sem_t *semB;

    semA = sem_open("/semA", 0);
    semB = sem_open("/semB", 0);

    while(1){
        sem_wait(semB);
        printf("Proceso B \n");
        sleep(1);
        sem_post(semA);
    }
    
}