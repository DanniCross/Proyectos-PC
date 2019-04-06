#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>

#define NR_LOOP 10000

static void * thread_1_function(void *args);
static void * thread_2_function(void *args);

static int counter = 0;

sem_t * semaforo;

int main(void) {
    sem_init(semaforo, 0, 1);

    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, *thread_1_function, NULL);
    pthread_create(&thread_2, NULL, *thread_2_function, NULL);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    
    sem_destroy(semaforo);

    printf("Valor counter %d \n", counter);

    return 0;
}

static void * thread_1_function(void *args) {
    for(int i = 0; i < NR_LOOP; i++)
    {
        sem_wait(semaforo);
        counter += 1;
        sem_post(semaforo);
    }
}

static void * thread_2_function(void *args) {
    for(int i = 0; i < NR_LOOP; i++)
    {
        sem_wait(semaforo);
        counter -= 1;
        sem_post(semaforo);
    }
}