#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_X 50
#define N 10

int main() {
    int vetorX[TAM_X];
    int vetorF[N];
    int *pX = vetorX;
    int *pF = vetorF;

    for (int i = 0; i < N; i++) {
        *(pF + i) = 0;
    }

    srand(time(NULL));
    for (int i = 0; i < TAM_X; i++) {
        *(pX + i) = rand() % N;
    }

    for (int i = 0; i < TAM_X; i++) {
        int valor = *(pX + i);
        *(pF + valor) = *(pF + valor) + 1;
    }

    puts("Vetor X (Valores):");
    for (int i = 0; i < TAM_X; i++) {
        printf("%d ", *(pX + i));
    }
    puts("");
    
    puts("\nVetor F (Frequência de Ocorrências):");
    puts("[Índice] = Frequência");
    for (int i = 0; i < N; i++) {
        printf("[%d] = %d\n", i, *(pF + i));
    }

    return 0;
}