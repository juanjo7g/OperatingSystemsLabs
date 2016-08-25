#include <stdio.h>

int main(){
    int v[] = {1,2,3,4,5,6,7};
    int *ptr_v = NULL;
    // ptr_v -> direccion
    // *ptr_v -> dato
    ptr_v = &v[1];
    printf("%d\n", *ptr_v);
    ptr_v += 2;
    *ptr_v = 10;
    printf("%d\n", *ptr_v);
    return 0;
}