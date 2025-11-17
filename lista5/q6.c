#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TAM 30
#define MX 50

double cemq(int *vetorx, int *vetory, int tamanho){
    double soma = 0.0;

    for(int i = 0; i < tamanho; i++){
        int diferenca = vetorx[i] - vetory[i];
        soma += diferenca * diferenca; 
    }

    return soma / tamanho; 
}

void geravetor(int *vetor, int tamanho, int maximo){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % maximo;
        printf("%d ", vetor[i]);
    }
}

int main(){
    srand(time(NULL));

    int vetorx[TAM];
    int vetory[TAM];

    printf("Vetor X:\n");
    geravetor(vetorx, TAM, MX);

    printf("\n\nVetor Y:\n");
    geravetor(vetory, TAM, MX);

    double eqm = cemq(vetorx, vetory, TAM);

    printf("\n\nErro quadrático médio: %.4f\n", eqm);

    return 0;
}

