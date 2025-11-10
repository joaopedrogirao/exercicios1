#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 3
#define MX 100
int main(){
    int n;
    int matriz[TAM][TAM];
    srand(time(NULL));
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            matriz[i][j] = rand() % MX;


        }

    }
    puts("Digite um número inteiro:");
    scanf("%d", &n);

    
    puts("Matriz gerada:");
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            printf("%d\t", matriz[i][j]);


        }
         printf("\n");
    }
 
 
    int contador = 0;
 for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(matriz[i][j] == n){
                contador++;
      } 
    }
}
        printf("O número %d apareceu %d vezes", n, contador);

return 0;
}