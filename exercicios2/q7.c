#include <stdio.h>
int main(){

    float n1, n2, div;

    puts("Digite o dividendo:");
    scanf("%f", &n1);

    puts("Digite o divisor:");
    scanf("%f", &n2);   

    while(n2 == 0){
        puts("Divisor inválido. Digite outro número:");
        scanf("%f", &n2);   


    }
    div = n1 / n2;
    printf("O resultado da divisão é %.2f\n", div);     

    return 0;   
}