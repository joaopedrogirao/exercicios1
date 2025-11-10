#include <stdio.h>
#define TAM 15
int main(){

    float vetor[TAM] = {1,2,3,3,4,4,4,7,5,10,15,23,14,15,16};

    float menor = vetor[0];
    float maior = vetor[0];

    for(int i = 0; i < TAM; i++){
        if(vetor[i] < menor){
            menor = vetor[i];
        }

        else if(vetor[i] > maior){
            maior = vetor[i];
        }


    }


    printf("Maior + Menor = %.1f", maior + menor);


return 0;


}