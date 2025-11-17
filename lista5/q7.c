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

void bmatriz(int *matriz, int *s, int tamanho, int t){

    for(int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){

             s[i * tamanho + j] = (matriz[i * tamanho + j] > t) ? 1 : 0;
                printf("%3d ", s[i * tamanho + j]); 
    }
        printf("\n");

    }

}

int main(){

    srand(time(NULL));
    int t = 9;
    int matriz[TAM][TAM];
    int s[TAM][TAM];

    popularmatriz(&matriz[0][0], TAM, MX);

    printf("\nMatriz binarizada:\n");

    bmatriz(&matriz[0][0], &s[0][0], TAM, t);


    return 0;


}