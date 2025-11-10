#include <stdio.h>

int main(){
    int var1 = 5, var2 = 40;
    int *p1 = &var1;
    int *p2 = &var2;

    int soma = *p1 + *p2;
    int *p3 = &soma;
    printf("%p - %d\n", p1, *p1);
    printf("%p - %d\n", p2, *p2);
    printf("%p - %d", p3, *p3);
}