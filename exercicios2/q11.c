#include <stdio.h>

int main() {
    int p1, p2;
    int inicio, fim;

    puts("Digite o primeiro número do intervalo");
    scanf("%d", &p1);

    puts("Digite o segundo número do intervalo");
    scanf("%d", &p2);

    if (p1 < p2) {
        inicio = p1;
        fim = p2;
    } else {
        inicio = p2;
        fim = p1;
    }

    printf("\nQuadrados dos múltiplos de 4 no intervalo de %d a %d:\n", inicio, fim);

    for (int i = inicio; i <= fim; i++) {
        if (i % 4 == 0) {
            int quadrado = i * i;
            printf("%d\n", quadrado);
        }
    }

    return 0;
}