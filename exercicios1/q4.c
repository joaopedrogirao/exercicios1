#include <stdio.h>

int main(){

    float conta;
    
    puts("Escreva o valor da conta: ");
    scanf("%f", &conta);

    printf("Valor a ser pago: %.2f\n", conta * 1.1);

    return 0;

}