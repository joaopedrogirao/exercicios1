#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main() {
    int vetor[TAM];
    int *p = vetor;
    int aux;
    int flag;

    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        *(p + i) = rand() % 100;
    }

    puts("Vetor desordenado:");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p + i));
    }
    puts("");

    for (int i = 0; i < TAM - 1; i++) {
        flag = 1;
        for (int j = 0; j < TAM - 1 - i; j++) {
            
            if (*(p + j) > *(p + j + 1)) {
                
                aux = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = aux;
                
                flag = 0;
            }
        }
        if (flag) break;
    }

    puts("Vetor ordenado:");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", *(p + i));
    }
    puts("");

    return 0;
}