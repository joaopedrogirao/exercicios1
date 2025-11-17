#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 30
#define MX 50

void geravetor(int *vetor, int tamanho, int maximo){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % maximo;
        printf("%d ", vetor[i]);
    }
}

    void ordenar(int *vetor, int tamanho){
    int flag;

    for (int i = 0; i < tamanho - 1; i++) {
        flag = 1;
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j+1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                flag = 0;
            }
        }
        if (flag) break;
    }
}



float mediana(int *vetor, int tamanho) {
    if (tamanho % 2 == 1) {
        return vetor[tamanho/2];
    } else {
        
        return (vetor[tamanho/2 - 1] + vetor[tamanho/2]) / 2.0;
    }
}


int moda(int *vetor, int tamanho, int maximo) {
    int freq[maximo];
    
    for (int i = 0; i < maximo; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < tamanho; i++) {
        freq[vetor[i]]++;
    }


    int moda = 0;
    int maxFreq = freq[0];

    for (int i = 1; i < maximo; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            moda = i;
        }
    }

    return moda;
}

int somavetor(int *vetor, int tamanho){
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }
    return soma;
}


int main(){

    srand(time(NULL));

    int vetor[TAM];
    
    geravetor(vetor, TAM, MX);

    int soma = somavetor(vetor, TAM);
    
    ordenar(vetor, TAM);
   
    float med = mediana(vetor, TAM);

    float media = (float)soma / TAM;

    printf("\nMédia = %f", media);
    printf("\nMediana = %.2f", med);
    int m = moda(vetor, TAM, MX);
    printf("\nModa = %d", m);

    return 0;

}

