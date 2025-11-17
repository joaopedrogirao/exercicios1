/*Escreva um programa em C que informe se o somat ́orio da diagonal principal de matriz N x N
gerada  ́e par ou  ́ımpar.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 3
#define MX 20

void popularmatriz(int *matriz, int tamanho, int maximo){

    for(int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            matriz[i * tamanho + j] = rand() % maximo;
        }
    }

    for(int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            printf("%3d ", matriz[i * tamanho + j]);
        }
        printf("\n");
    }
}

int somadiagonal(int *matriz, int tamanho){
    int soma = 0;

    for(int i = 0; i < tamanho; i++){
        soma += matriz[i * tamanho + i];
            
    }
    return soma;

}

void parouimpar(int valor) {
    printf("Somatório da diagonal principal (%d) é: ", valor);

    if (valor % 2 == 0) {
        printf("PAR\n");
    } else {
        printf("ÍMPAR\n");
    }
}


int main(){

    srand(time(NULL));
    int matriz[TAM][TAM];
    
    popularmatriz(&matriz[0][0], TAM, MX);
    int somadiag = somadiagonal(&matriz[0][0], TAM);

    printf("Somatório da diagonal principal = %d\n", somadiag);

    parouimpar(somadiag);

    return 0;

}