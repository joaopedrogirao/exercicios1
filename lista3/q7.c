#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAM 3

int main(){
    int vetor[TAM];

    srand(time(NULL));
    int soma = 0;
    int produto = 1;
    for(int i = 0; i < TAM; i++){
        vetor[i] = rand() % 20;
        printf("%d ", vetor[i]);
        soma = soma + vetor[i];
        produto = produto * vetor[i];
    
    }
    
    float mediaa = (float)soma / TAM;
    float mediag = pow(produto, 1.0 / TAM);

    printf("Média aritmética: %.1f\n", mediaa);
    printf("Média geométrica: %.1f", mediag);

    return 0;
}