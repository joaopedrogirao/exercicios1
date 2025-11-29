#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct aleatoria{
    int *vetor;
    int qntdelementos;
    float media;

};

int main(){
    struct aleatoria a;

    puts("Quantos elementos deseja gerar:");
    scanf("%d", &a.qntdelementos);

    a.vetor = (int *) malloc(a.qntdelementos * sizeof(int));

    if(a.vetor == NULL){
        puts("Falha");
        return 1;
    }

    srand(time(NULL));

    for(int i = 0; i < a.qntdelementos; i++){  
    a.vetor[i] = rand() % 51;
        printf("%d ", a.vetor[i]);

}
    float soma = 0.0;
    for(int i = 0; i < a.qntdelementos; i++){
        soma += a.vetor[i];

    }

    a.media = soma / a.qntdelementos;


    printf("Média = %f", a.media);

    free(a.vetor);
    return 0;



}

