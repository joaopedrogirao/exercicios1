#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 30
#define MX 100

void imprimirvetor(int *vetor, int tamanho, int maximo){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % maximo;
        printf("%d ", vetor[i]);
    }

}


int main(){

    srand(time(NULL));

    int vetor[TAM];

    printf("Vetor original:\n");
    imprimirvetor(vetor, TAM, MX);

   
    int min = vetor[0];
    int max = vetor[0];

    for(int i = 1; i < TAM; i++){
        if(vetor[i] < min) min = vetor[i];
        if(vetor[i] > max) max = vetor[i];
    }

    printf("\n\nMin: %d\n", min);
    printf("Max: %d\n\n", max);

    if(max - min == 0){
        puts("Não é possível normalizar");
    }
    else{
        puts("Vetor normalizado:");
        for(int i = 0; i < TAM; i++){
            float valornormalizado =
                (float)(vetor[i] - min) / (float)(max - min);

            printf("%.4f ", valornormalizado);
        }
    }

    printf("\n");
    return 0;
}
