#include <stdio.h>
#include <stdlib.h> // Para manejo dinamico de memoria con malloc (llamado al sistema para reservar memoria)

void getValues(float *ptr_grades, int size);
void showGrades(float *ptr_grades, int size);
float getAverage(float *ptr_grades, int size);

int main(){
    float grades[5];
    float *ptr_grades;
    //ptr_grades = &grades[0]; // Estatico
    ptr_grades = (float*) malloc(sizeof(float)*5); // Dinamico
    getValues(ptr_grades, 5);
    showGrades(ptr_grades, 5);
    printf("El promedio es %f\n", getAverage(ptr_grades, 5));
    //*ptr_grades = 8;
    //*(ptr_grades+4) = 80;
    //printf("%f\n", *(ptr_grades+4));
    free(ptr_grades); // Dinamico
}

void getValues(float *ptr_grades, int size){
    int i;
    float grade;
    for (i=0; i<size; i++){
        printf("Ingrese la nota %d\n", i+1);
        scanf("%f", &grade);
        *(ptr_grades+i) = grade;
    }
}

void showGrades(float *ptr_grades, int size){
    int i;
    for(i=0; i<size; i++){
        printf("Nota %d : %f\n", i+1, *(ptr_grades+i));
    }
}

float getAverage(float *ptr_grades, int size){
    int i;
    float sum = 0;
    float average;
    for(i=0; i<size; i++){
        sum = sum + *(ptr_grades+i);
    }
    average = sum / size;
    return average;
}