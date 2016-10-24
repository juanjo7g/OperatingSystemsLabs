#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define NUMTHREADS 4

struct parameters{
	int a;
	int b;
	int c;
};

//int sum = 0; /* this data is shared by the thread(s) */
void *operar(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
	pthread_t tid[NUMTHREADS]; /* the thread identifier */
	unsigned char cnt =0;

	int *response[NUMTHREADS];
	int value = atoi(argv[1]);
	
	struct parameters params[4];
	
	if (argc != 3){
		fprintf(stderr,"usage: a.out <numero1> <numero2>\n");
		return -1;
	}
	
	/* create the thread */
	for(cnt=0; cnt < NUMTHREADS; cnt++){
		params[cnt].a = atoi(argv[1]);
		params[cnt].b = atoi(argv[2]);
		params[cnt].c = cnt;
		pthread_create(&tid[cnt], NULL, operar, (void*)&params[cnt]);
	}
	/* wait for the thread to exit */

	pthread_join(tid[0], (void**) &response[0]);
	printf("Suma %d\n", *response[0]);
	free(response[0]);
	pthread_join(tid[1], (void**) &response[1]);
	printf("Resta %d\n", *response[1]);
	free(response[1]);
	pthread_join(tid[2], (void**) &response[2]);
	printf("Multiplicacion %d\n", *response[2]);
	free(response[2]);
	pthread_join(tid[3], (void**) &response[3]);
	printf("Division %d\n", *response[3]);
	free(response[3]);
	
	return EXIT_SUCCESS;
}

/* The thread will begin control in this function */
void *operar(void *param)
{
	int i =	0;
	struct parameters *ptr_params = (struct parameters *)param;
	int a = ptr_params->a;
	int b = ptr_params->b;
	int c = ptr_params->c;
	int sum = 0;
	switch(c){
		case 0:
			sum = a+b;
		break;
		case 1:
			sum = a-b;
		break;
		case 2:
			sum = a*b;
		break;
		case 3:
		sum = a/b;
		break;
	}
	int *ptr = (void *) malloc(sizeof(int));
	
	*ptr = sum;	
		
	pthread_exit(ptr);
}
