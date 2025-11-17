#include <stdio.h>

int main(){
    float saldo, dolar;

    puts("Digite a cotação atual do dólar em relação ao real: ");
    scanf("%f", &dolar);

    puts("Digite o saldo em real que deseja converter: ");
    scanf("%f", &saldo);

    printf("Seu saldo em dólar é: $%.2f", saldo / dolar);

    return 0;

    
}