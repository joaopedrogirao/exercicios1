#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 10
#define MX 10

double erro_mae(int a, int b) {
    return fabs((double)a - b);
}

double erro_mse(int a, int b) {
    double diferenca = (double)a - b;
    return diferenca * diferenca;
}

double calcular_erro_generico(int *vetA, int *vetB, int tamanho, double (*func_erro)(int, int)) {
    double soma = 0.0;
    for(int i = 0; i < tamanho; i++) {
        soma += func_erro(vetA[i], vetB[i]);
    }
    return soma / tamanho;
}

int main() {
    int vetora[TAM];
    int vetorb[TAM];

    srand(time(NULL));

    for(int i = 0; i < TAM; i++) {
        vetora[i] = rand() % MX;
        vetorb[i] = rand() % MX;
    }

    printf("Vetor A: ");
    for(int i = 0; i < TAM; i++) {
        printf("%d ", vetora[i]);
    }
    printf("\n");

    printf("Vetor B: ");
    for(int i = 0; i < TAM; i++) {
        printf("%d ", vetorb[i]);
    }
    printf("\n\n");

    double mae = calcular_erro_generico(vetora, vetorb, TAM, erro_mae);
    double mse = calcular_erro_generico(vetora, vetorb, TAM, erro_mse);

    printf("MAE: %.4f\n", mae);
    printf("MSE: %.4f\n", mse);

    return 0;
}