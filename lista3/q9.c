#include <stdio.h>
#define TAM 3
int main(){

    int matriz[TAM][TAM];

    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            printf("Elemento [%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);


        }

    }

    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            printf("%d\t", matriz[i][j]);



        }
         printf("\n");
    }

    puts("Diagonal Principal:");
    for(int i = 0; i < TAM; i++){
        printf("%d ", matriz[i][i]);
    }
printf("\n");

return 0;
}