/*
	1. Programa para determinar si un numero entero es par o impar.
*/
#include <stdio.h>
#include <string.h>

void strip_newline(char *str, int size){
    int i;
    /* remove the null terminator */
    for(i = 0; i < size; ++i){
        if(str[i] == '\n'){
            str[i] = '\0';
            /* we're done, so just exit the function by returning */
            return;
        }
    }
    /* if we get all the way to here, there must not have been a newline! */
}

int main(){
	int number;
	char numberStr[50];
	printf("Ingrese un numero: ");
	fgets(numberStr, 50, stdin);
	strip_newline(numberStr, 50);
	
	if(isNumber(numberStr, strlen(numberStr)) == 1){
		
	} else{
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

int isNumber(char *str, int size){
	int i;
	for (i = 0; i < size; ++i){
       
		printf("%d\n", *str);
		
		if (str[i] == '\n'){
            str[i] = '\0';
            return 1;
        }
    }
	return 1;
}