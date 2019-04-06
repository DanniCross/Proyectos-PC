#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void personal(int);

void main(){
 if(signal(SIGINT, personal) == SIG_ERR){
     perror("No se puede cambiar señal");
 }
 while(1)
	 pause();
}

void personal(int nsign){
    signal(SIGINT, SIG_IGN);
}
