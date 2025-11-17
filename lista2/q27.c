#include <stdio.h>
int main(){
    int n;
    int maior, menor;
    int numeros_lidos = 0;
    long long produto;

    puts("Digite números inteiros");
    puts("O programa irá parar quando você digitar um número negativo e par");

    puts("Digite um número:");
    scanf("%d", &n);

    while (n >= 0 || n % 2 != 0) {

        if (numeros_lidos == 0) {
            maior = n;
            menor = n;
        } else {
            if (n > maior) {
                maior = n;
            }
            else if (n < menor) {
                menor = n;
            }
        }
        numeros_lidos++;
        
        printf("Maior número até o momento:%d\nMenor número até o momento:%d\n", maior, menor);
        puts("Digite um número:");
        scanf("%d", &n);
    }


    if (numeros_lidos == 0) {
        puts("Você não digitou nenhum número válido.");
    } else {
        produto = (long long)maior * menor;
        printf("Maior número: %d\n", maior);
        printf("Menor número: %d\n", menor);
        printf("Produto (maior x menor): %lld\n", produto);
    }

    return 0;
}


