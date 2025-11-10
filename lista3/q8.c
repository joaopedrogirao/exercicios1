#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100
int main(){
        int vetor[TAM];
        int n1, n2, min, max;

        puts("Digite o primeiro número do intervalo");
        scanf("%d", &n1);

        puts("Digite o segundo número do intervalo");
        scanf("%d", &n2);

        if (n1 > n2) {
        max = n1;
        min = n2;
    } else {
        max = n2;
        min = n1;
    }
    int larguraintervalo = max - min + 1;
        srand(time(NULL));
        puts("Vetor desordenado:");
        for(int i = 0; i < TAM; i++){
        vetor[i] = (rand() % larguraintervalo) + min;
        printf("%d ", vetor[i]);
    }
   
    int aux;
    for(int i = 0; i < TAM-1; i++){
        for(int j = i + 1; j < TAM; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
      
    }

    puts("\n\nVetor ordenado:");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);    
    }

return 0;


}