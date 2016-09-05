#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS_NAME 50

void menu(char *option);
void registerEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int *hours, int *empl_count, int emp_max);
void showEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int *hours, int empl_count);

int main(int argc, char *argv[]){
    char option = '-';
    int MAX_EMPL = 50;
    
    char (*ptr_names)[MAX_CHARS_NAME];
    float *ptr_salaries;
    int *ptr_hours;
    
    int empl_count = 0;
    int empl_max;
    
    if (argc != 2) {
        printf("Error, la ejecución del programa debe ser: %s <num_max_trabajadores>", argv[0]);
        return 1;
    }

    empl_max = atoi(argv[1]);
    MAX_EMPL = empl_max;
    
    ptr_names = (char(*)[MAX_CHARS_NAME]) malloc(sizeof(char [MAX_CHARS_NAME]) * MAX_EMPL);
    ptr_salaries = (float*) malloc(sizeof(float) * MAX_EMPL);
    ptr_hours = (int*) malloc(sizeof(int) * MAX_EMPL);
    
    
    do{
        menu(&option);
        
        switch(option){
            case 'a':
                registerEmployees(ptr_names, ptr_salaries, ptr_hours, &empl_count, MAX_EMPL);
                break;
            case 'b':
                showEmployees(ptr_names, ptr_salaries, ptr_hours, empl_count);
                break;
            case 'q':
                break;
            default:
                printf("\nOpción invalida.\n");
                break;
        
        }
    } while(option != 'q');
    
}

void menu(char *option) {
    printf("\nMENÚ DE OPCIONES\n");
    printf("a) Registrar trabajadores\n");
    printf("b) Ver lista de trabajadores\n");
    printf("c) Ver nómina\n");
    printf("q) Salir del programa\n");
    
    printf("Seleccione una opción: ");
    setbuf(stdin, NULL);
    scanf("\n%c", option);
}

void registerEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int *hours, int *empl_count, int empl_max){
    int n = 0;
    int i = 0;
    
    printf("Ingrese el número de empleados a registrar: ");
    setbuf(stdin, NULL);
    scanf("%d", &n);
    
    if (*empl_count + n > empl_max) {
        printf("El número de empreados a registrar sobrepasa la memoria.\n");
        return;
    }
    
    for(i = *empl_count; i< *empl_count+n; i++){
        printf("\nEmpleado #%d:\n", i);
        printf("Ingrese el nombre:");
        setbuf(stdin, NULL);
        scanf("%s", (char *)(names + i));

        printf("Ingrese el salario:");
        setbuf(stdin, NULL);
        scanf("%f", (salaries + i));
        
        printf("Ingrese las horas extra:");
        setbuf(stdin, NULL);
        scanf("%d", (hours + i));
    }
    *empl_count = *empl_count + n;
}

void showEmployees(char (*names)[MAX_CHARS_NAME], float *salaries, int *hours, int empl_count){
    int i = 0;
    printf("\n\n%14s|%14s|%14s", "Nombre", "Salario Base", "Horas Extra\n");
    for(i = 0; i < empl_count; i++){
        printf("%14s|%14.2f|%14d\n", *(names + i), *salaries + i, *hours + i);
    }
    printf("\n\n");
}