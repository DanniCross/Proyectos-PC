#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char *nombre;
    int edad;
    int cumpleanos;
}

trabajadores;
trabajadores *trab;
void vaciar(char temp[]);
void copiar(char temp[], int i);

void main(){
    char temp[50];
    char aux;
    int cont = 0;
    FILE *f;
    f = fopen("/home/josec/Documentos/VIM/Proyecto I/Prueba.txt" , "r");
    if(f == NULL){
        printf("No se ha podido abrir el fichero.\n");
	exit(1);
    }

    while(!feof(f)){
        fgets(temp, 50,f);
	cont++;
    }

    rewind(f);
    trab = (trabajadores*)malloc(cont*sizeof(trabajadores)+1);
    
    if(trab == NULL){
        printf("No se ha podido reservar la memoria.\n");
	exit(1);
    }

    for(int i = 0; !feof(f); i++){
        vaciar(temp);
        aux = '0';
	for(int j = 0; aux != ' '; j++){
	    aux = fgetc(f);
            if(aux != '-'){
	        temp[j] = aux;
	    }
	}
	copiar(temp, i);
	fgets(temp, 10, f);
	trab[i].edad = atoi(temp);
	trab[i].cumpleanos = atoi(temp);

	printf("Nombre: %s Edad: %i Cumpleanos: %i.\n", trab[i].nombre, trab[i].edad, trab[i].cumpleanos);
    }

    system("pause");
}

void vaciar(char temp[]){
    for(int i = 0; i < 50; i++){
        temp[i] = '\0';
    }
}

void copiar(char temp[], int i){
    int N = strlen(temp) + 1;
    trab[i].nombre = (char*)malloc(N*sizeof(char)+1);
    if(trab[i].nombre == NULL){
        printf("No se ha podido reservar memoria.\n");
        exit(1);
    }
    strcpy(trab[i].nombre, temp);
    if(trab[i].nombre, temp);
}
