#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMTHREADS 10
#define MAX_CHARS_LINE 200

FILE *openFile(char *filename, char *mode); // Abre un archivo para escritura o lectura
int *readFile(FILE *file); // Lee y procesa un archivo
int *increaseNumbers(int *numbers); // Aumenta la memoria dinámica
int *lineProcess(char *line, int *numbers); // Procesa una línea del archivo

void *isPerfect(void *params); /* threads call this function */

int count = 0;

int main(int argc, char *argv[])
{
	unsigned char cnt =0;
	pthread_t *tids; /* the thread identifier */
	int *response;
	int *numbers;
    FILE *file;

	
	if (argc != 2) {
        puts("Error al ejecutar, debes hacerlo de la siguiente forma");
        printf("%s <archivo_entrada>\n", argv[0]);
        return 1;
    }
    
    file = openFile(argv[1], "r");
    
    numbers = readFile(file);
    
    tids = malloc(sizeof(pthread_t) * count);
    
	/* create the thread */
	for(cnt=0; cnt < NUMTHREADS; cnt++){
		pthread_create((tids+cnt), NULL, isPerfect, (void *)(numbers + cnt));
	}
	
	for (cnt = 0; cnt < NUMTHREADS; cnt++) {
	    // Se espera que termine un hilo determinado
	    pthread_join(*(tids + cnt), (void **)&response);
	    
	    // Verificar el resultado del hilo
        if (*response != 0) {
          printf("%d es un número perfecto\n", *(numbers + cnt));
        }
    
        // Liberar memoria del dato retornado por el hilo
        free(response);
	}

    // Liberar memoria de los números e hilos
    free(tids);
    free(numbers);
    
    // Cerrar archivos
    fclose(file);
	
	return EXIT_SUCCESS;
}

FILE *openFile(char *filename, char *mode) {
  FILE *file;

  file = fopen(filename, mode);

  // Validar si el archivo fue abierto
  if (!file) {
    printf("Error al abrir el archivo: %s\n", filename);
    exit(1);
  }

  return file;
}

int *readFile(FILE *file) {
  int *numbers = NULL;
  char line[MAX_CHARS_LINE];

  // Mientras se leen las lineas, se incrementa la memoria dinamica y se guardan los datos
  while (fgets(line, MAX_CHARS_LINE, file)) {
    numbers = lineProcess(line, numbers);
  }

  return numbers;
}

int *increaseNumbers(int *numbers) {
  count++;

  numbers = (int *)realloc(numbers, sizeof(int) * count);

  if (numbers == NULL) {
    puts("Error al incrementar la memoria.");
    exit(1);
  }

  return numbers;
}

int *lineProcess(char *line, int *numbers) {
  char *num;
  char sep[] = ";";

  num = strtok(line, sep);

  while(num != NULL) {
    numbers = increaseNumbers(numbers);

    *(numbers + count - 1) = atoi(num);

    num = strtok(NULL, ";");
  }

  return numbers;
}

void *isPerfect(void *param) {
  int i;
  int num = *((int *)param);
  int max = num / 2 + 1;
  int sum = 0;

  // Reservar memoria para retornar al programa principal
  int *ptr = (void *)malloc(sizeof(int));

  // Realizar la sumatoria desde 1 hasta n/2
  for (i = 1; i < max; i++) {
    if (num % i == 0) {
      sum += i;
    }
  }

  // Verificar si la sumatoria es igual al número inicial
  if (sum == num) {
    *ptr = sum;
  } else {
    *ptr = 0;
  }

  // Retornar dirección de memoria al programa principal
  pthread_exit(ptr);
}