#include <stdio.h>

int main(){

    int x;

    puts("Digite um número inteiro: ");
    scanf("%d", &x);

    printf("O triplo de %d é: %d\n", x, x * 3);
    printf("O quadrado de %d é: %d\n", x, x * x);
    printf("A metade de %d é: %d\n", x, x / 2);

    return 0;




}