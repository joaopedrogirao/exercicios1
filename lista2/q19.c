#include <stdio.h>
int main(){
    
    int inicio, fim, p1, p2;
    puts("Digite o primeiro número do intervalo:");
    scanf("%d", &p1);

    puts("Digite o segundo número do intervalo:");
    scanf("%d", &p2);

    if (p1 < p2) {
        inicio = p1;
        fim = p2;
    } else {
        inicio = p2;
        fim = p1;
    }

    int soma = 0; 

    for(int i = inicio; i <= fim; i++){
        soma += i;




    }

    int quantidade = fim - inicio + 1;
    float media = (float)soma / quantidade;

    printf("A média é: %.2f", media);

    return 0;


}