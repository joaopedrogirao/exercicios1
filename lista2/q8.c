#include <stdio.h>
int main(){

    float total, entrada;
    int prestacao;

    puts("Digite o valor total da mercadoria: ");
    
    scanf("%f", &total);

    prestacao = (total / 3);      
    entrada = total - (prestacao * 2);

    printf("O valor da entrada é R$ %.2f\n", entrada);
    printf("O valor das duas prestações é R$ %d\n", prestacao);   
    return 0;
}

