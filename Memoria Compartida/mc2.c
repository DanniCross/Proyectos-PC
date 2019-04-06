#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 75

main ()
{
	int shmid;
	char *addr, *pint;
	/* Obtener dirección de la región de memoria */
	shmid = shmget (SHMKEY, 1, 0777);
	/* Enlazar región al espacio de direccionamiento del proceso */
	addr = shmat (shmid, 0, 0);
	pint = (char *) addr; /* Reservar addr */
	/* Espera a que el contenido de la primera dirección tenga un valor distinto de 0 */
	while (*pint == 0)
	{
		//sleep(1);
		printf("valor: %i\n", *pint);
	}
	printf("valor: %i\n", *pint);
	/* Esperar 1 segundo */
	printf ("\n Continuo la ejecución \n");
	/* Separar la región del espacio de direccionamiento del proceso */
	shmdt (addr);
	return 0;
} /* fin de la función main */
