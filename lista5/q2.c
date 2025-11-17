#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 30
#define MX 100

void encontraPares(int *vet, int **primeiro, int **ultimo) {
    *primeiro = NULL;
    *ultimo = NULL;

    for (int i = 0; i < TAM; i++) {
        if (vet[i] % 2 == 0) {
            *primeiro = &vet[i];
            break;
        }
    }

    for (int i = TAM-1; i >= 0; i--) {
        if (vet[i] % 2 == 0) {
            *ultimo = &vet[i];
            break;
        }
    }
}


int main(){
    srand(time(NULL));

    int vetor[TAM];
    int *p = vetor;

    for(int i = 0; i< TAM; i++){
        vetor[i] = rand() % MX;
        printf("%d ", vetor[i]);
    }
        
        int *pPrimeiro, *pUltimo;


    encontraPares(vetor, &pPrimeiro, &pUltimo);

    
    if (pPrimeiro != NULL) {
        printf("\n\nPrimeiro par (%d) no endereço: %p", *pPrimeiro, pPrimeiro);
        printf("\nÚltimo par (%d) no endereço: %p\n", *pUltimo, pUltimo);
    }
    else {
        printf("\n\no vetor não possui números pares");
    }

    return 0;
}