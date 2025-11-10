#include <stdio.h>
int main(){
    int var1 = 5, var2 = 40;
    int *p1 = &var1;
    int *p2 = &var2;

    printf("Antes:\nVar1: %d, Var2: %d\n", var1, var2);
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;

    printf("Depois\nVar1: %d, Var2: %d\n", var1, var2);

    return 0;
}
