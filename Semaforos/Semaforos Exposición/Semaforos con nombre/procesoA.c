#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>

int main(void) {
    sem_t *semA;
    sem_t *semB;
    int valSemA;
    int valSemB;

    sem_unlink("/semA");
    sem_unlink("/semB");
    
    semA = sem_open("/semA", O_CREAT|O_EXCL, 0664, 1);
    semB = sem_open("/semB", O_CREAT|O_EXCL, 0664, 0);

    sem_getvalue(semA, &valSemA);
    sem_getvalue(semB, &valSemB);

    printf("Valor semaforo A: %d \n", valSemA);
    printf("Valor semaforo B: %d \n", valSemB);

    while(1){
        sem_wait(semA);
        printf("Proceso A \n");
        sleep(1);
        sem_post(semB);
    }
    
}