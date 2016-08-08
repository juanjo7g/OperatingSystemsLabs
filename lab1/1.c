/*
	1. Programa para determinar si un numero es par o impar.
*/
#include <stdio.h>

int main(){
	int numero;
	printf("Ingrese un numero: ");
	if (scanf("%d", &numero) != 1){
		printf("Numero invalido\n");
		return 1;
	}
	if (numero%2 == 0){
		printf("El numero %d es par.\n", numero);
	}else{
		printf("El numero %d es impar.\n", numero);
	}
	return 0;
}