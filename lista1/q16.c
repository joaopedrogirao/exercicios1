#include <stdio.h>
#include <stdlib.h>
int main(){

    int n;
    
    puts("Digite um número inteiro:");
    scanf("%d", &n);

    int modulo = abs(n);

    printf("O módulo de %d é %d", n, modulo);

    return 0;




}