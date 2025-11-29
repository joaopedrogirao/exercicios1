#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define TAM 20

void zerar_matriz(int *ptr_matriz, int total_elementos);
void preencher_vetor_aleatorio(int *ptr_vetor, int tamanho, int max_valor);
void calcular_coocorrencia(int *ptr_x, int *ptr_y, int *ptr_matriz, int tam_vetor, int largura_matriz);
void imprimir_vetor(int *ptr_vetor, int tamanho, char *nome);
void imprimir_matriz(int *ptr_matriz, int linhas, int colunas);

int main(){
    int vetorx[TAM];
    int vetory[TAM];
    int matriz[N][N];

    srand(time(NULL));

    zerar_matriz((int *)matriz, N * N);

    preencher_vetor_aleatorio(vetorx, TAM, N);
    preencher_vetor_aleatorio(vetory, TAM, N);

    imprimir_vetor(vetorx, TAM, "X");
    imprimir_vetor(vetory, TAM, "Y");

    calcular_coocorrencia(vetorx, vetory, (int *)matriz, TAM, N);

    imprimir_matriz((int *)matriz, N, N);

    return 0;
}

void zerar_matriz(int *ptr_matriz, int total_elementos) {
    int *final = ptr_matriz + total_elementos;
    for (int *p = ptr_matriz; p < final; p++) {
        *p = 0;
    }
}

void preencher_vetor_aleatorio(int *ptr_vetor, int tamanho, int max_valor) {
    int *final = ptr_vetor + tamanho;
    for (int *p = ptr_vetor; p < final; p++) {
        *p = rand() % max_valor;
    }
}

void calcular_coocorrencia(int *ptr_x, int *ptr_y, int *ptr_matriz, int tam_vetor, int largura_matriz) {
    for(int i = 0; i < tam_vetor; i++) {
        int linha = *(ptr_x + i);
        int coluna = *(ptr_y + i);
        int deslocamento = (linha * largura_matriz) + coluna;
        (*(ptr_matriz + deslocamento))++;
    }
}

void imprimir_vetor(int *ptr_vetor, int tamanho, char *nome) {
    printf("Vetor %s: ", nome);
    int *final = ptr_vetor + tamanho;
    for (int *p = ptr_vetor; p < final; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

void imprimir_matriz(int *ptr_matriz, int linhas, int colunas) {
    printf("\nMatriz:\n");
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            int valor = *(ptr_matriz + (i * colunas) + j);
            printf("%d ", valor);
        }
        printf("\n");
    }
}