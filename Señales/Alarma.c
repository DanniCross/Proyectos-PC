#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    if(alarm(5*10) > 0){
        printf("Ya se ha programado la alarma para 5 segundos");
    }
    sleep(30*10);//Detener la ejecucion para que la alarma actue
              //Si el programa llega aquí algo anda mal
    printf("Como diablos lleguo aca\n");
    return 0;
}
