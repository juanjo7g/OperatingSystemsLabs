#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMTHREADS 10

void *randomNumber(); /* threads call this function */

int main(int argc, char *argv[])
{
	unsigned char cnt =0;
	pthread_t tid[NUMTHREADS]; /* the thread identifier */
	int *response[NUMTHREADS];
	
	/* create the thread */
	for(cnt=0; cnt < NUMTHREADS; cnt++){
		pthread_create(&tid[cnt], NULL, randomNumber, &cnt);
	}
	/* wait for the thread to exit */
	
	 // Esperar que todos los hilos terminen
	  for (cnt = 0; cnt < NUMTHREADS; cnt++) {
	    // Se espera que termine un hilo determinado
	    pthread_join(tid[cnt], (void **)&response[cnt]);
	  }

	puts("");

	  // Imprimir los números organizados de acuerdo a la ejecución
	  for(cnt=0; cnt < NUMTHREADS; cnt++){
	    printf("Hilo %d -> %d\n", (int)tid[cnt], *response[cnt]);
	
	    // Liberar la memoria dínamica reservada en el hilo
	    free(response[cnt]);
	  }

	return EXIT_SUCCESS;
}

void *randomNumber() {
  unsigned int num;
  // Reservar memoria dínamica para retornar al programa principal
  int *number = malloc(sizeof(int));

  FILE *f;

  f = fopen("/dev/random", "r");

  fread(&num, sizeof(num), 1, f);

  fclose(f);

  *number = num % 1000;

  printf("Hilo %d -> %d\n", (int)pthread_self(), *number);

  // Retornar dirección de memoria dínamica
  pthread_exit(number);
}