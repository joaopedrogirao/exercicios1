#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 30
#define MX 40

void escolhevetor(float *vetor, int tamanho, int maximo){

    for(int i = 0; i < tamanho; i++){
        vetor[i] =((float)rand() / RAND_MAX) * maximo;
        printf("%.2f ", vetor[i]);
    }
}

void somavetor(float *vetor, float *soma, int tamanho){
    *soma = 0.0;

    for(int i = 0; i < tamanho; i++){
        *soma += vetor[i];
    }

}

int main(){
    srand(time(NULL));

    float vetor[TAM];

    escolhevetor(vetor, TAM, MX);

    float somatorio = 0.0;
    somavetor(vetor, &somatorio , TAM);

    printf("\nSomatório = %.2f", somatorio);

    return 0;


}