
#include <stdio.h>

int main(){

    int n;

    puts("Digite um número inteiro:");
    scanf("%d", &n);

    printf("o número %d é %s", n, !(n % 2) ? "par" : "impar");



return 0;



}