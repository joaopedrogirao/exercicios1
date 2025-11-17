#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 30
#define MX 100
int main(){
    srand(time(NULL));

    int vetor[TAM];
    int *p = vetor;

    for(int i = 0; i< TAM; i++){
        vetor[i] = rand() % MX;
        printf("%d ", vetor[i]);
    }
    int encontrou = 1;
    for(int i = 0; i< TAM; i++){
        if (vetor[i] % 2 == 0){
            printf("\nEndereço do primeiro par %d é: %p", vetor[i], p + i);
            encontrou = 0;
            break;
        }
    }

    if(encontrou) puts("O vetor não possui número par");

    return 0;




}