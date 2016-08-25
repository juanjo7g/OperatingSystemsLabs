/*
	Programa para sumar, restar, multiplicar y dividir.
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int option;
	int a,b;

	printf("Bienvenido a la calculadora de enteros.\n");
	while(1==1) {
		printf("Ingrese el numero la opción deseada:\n\n1. Sumar.\n2. Restar.\n3. Multiplicar.\n4. Dividir.\n\n0. SALIR.\n\n");

		if (scanf("%d", &option) != 1){
			printf("Opción invalida\n");
		}
		if (option == 0){
			return 0;
		}
		printf("Ingrese el primer numero: ");
		if (scanf("%d", &a) != 1){
			printf("Numero invalido\n");		
		}else{
			printf("Ingrese el segundo numero: ");
			if (scanf("%d", &b) != 1){
				printf("Numero invalido\n");
			}else{
				switch(option){
					case 1: 
						printf("La suma es: %d\n", add(a,b));
						break;
				}
			}
		}
		

	}
	return 0;
}

int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

int multiply(int a, int b){
	return a*b;
}

int divide(int a, int b){
	return a/b;
}