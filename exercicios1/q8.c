#include <stdio.h>

int main(){

    int n;
    puts("Escreva um número inteiro: ");
    
    scanf("%d", &n);

    printf("O antecessor de %d é %d e o sucessor é %d", n, n - 1, n + 1);

    return 0;



}