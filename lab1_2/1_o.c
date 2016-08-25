/*
	1. Programa para determinar si un numero es par o impar.
*/
#include <stdio.h>

int main(){
	int number;

	printf("Ingrese un numero: ");
	if (scanf("%d", &number) != 1){
		printf("Numero invalido\n");
		return 1;
	}
	if (isPair(number) == 1){
		printf("El numero %d es par.\n", number);
	}else{
		printf("El numero %d es impar.\n", number);
	}
	return 0;
}

int isPair(int number){
	if (number%2 == 0){
		return 1;
	}
	return 0;
}